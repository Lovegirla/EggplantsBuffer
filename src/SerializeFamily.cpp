#include <iostream>
#include <fstream>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include "SerializeFamily.h"
#include "iris_generated.h"
#include "include/iris.proto3.pb.h"


void SerializeFlatBuffer::Serialize()
{
    flatbuffers::FlatBufferBuilder builder;

    std::vector<flatbuffers::Offset<test::Flower>> flowerOffsets;
    for (const auto& data : m_flowers) {
        auto species = builder.CreateString(data.species);
        auto flower = test::CreateFlower(builder, data.sepalLength, data.sepalWidth,
                                         data.petalLength, data.petalWidth, species);
        flowerOffsets.push_back(flower);
    }

    auto flowersVector = builder.CreateVector(flowerOffsets);
    auto root = test::CreateFlowers(builder, flowersVector);

    builder.Finish(root);

    std::ofstream outFile("flatbuffer_data.bin", std::ios::binary);
    outFile.write(reinterpret_cast<const char*>(builder.GetBufferPointer()), builder.GetSize());
    outFile.close();
}

void SerializeFlatBuffer::DeSerialize()
{
    std::ifstream inFile("flatbuffer_data.bin", std::ios::binary);
    std::vector<char> buffer((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    const test::Flowers* flowers = test::GetFlowers(buffer.data());
    //test getbuffer() wjz

    // for (const auto& flower : *flowers->flowers()) {
    //     std::cout << "Species: " << flower->species()->c_str()
    //               << ", Sepal Length: " << flower->sepalLength()
    //               << ", Sepal Width: " << flower->sepalWidth()
    //               << ", Petal Length: " << flower->petalLength()
    //               << ", Petal Width: " << flower->petalWidth() << std::endl;
    // }
}

SerializeFamily::SerializeFamily()
{
}

SerializeFamily::~SerializeFamily()
{
}

void SerializeFamily::PrintFlowers()
{
    for (const auto& flower : m_flowers)
    {
        std::cout << "Species: " << flower.species
            << ", Sepal Length: " << flower.sepalLength
            << ", Sepal Width: " << flower.sepalWidth
            << ", Petal Length: " << flower.petalLength
            << ", Petal Width: " << flower.petalWidth<< std::endl;
    }
    
}

void SerializeFamily::setFlowers(std::vector<FlowerData> inFlowers)
{
    m_flowers.resize(inFlowers.size());
    for (size_t i = 0; i < inFlowers.size(); i++)
    {
        m_flowers[i] = inFlowers[i];
    }
}

void SerializeProtobuf::Serialize()
{
    test1::Flowers protobufFlowers;
    for (const auto& data : m_flowers) {
        test1::Flower* flower = protobufFlowers.add_flowers();
        flower->set_sepallength(data.sepalLength);
        flower->set_sepalwidth(data.sepalWidth);
        flower->set_petallength(data.petalLength);
        flower->set_petalwidth(data.petalWidth);
        flower->set_species(data.species);
    }

    std::ofstream outFile("protobuf_data.bin", std::ios::binary);
    protobufFlowers.SerializeToOstream(&outFile);
    outFile.close();
}

void SerializeProtobuf::DeSerialize()
{
    test1::Flowers protobufFlowers;
    std::ifstream inFile("protobuf_data.bin", std::ios::binary);
    protobufFlowers.ParseFromIstream(&inFile);

    //test getbuffer() wjz
    // for (const auto& flower : protobufFlowers.flowers()) {
    //     std::cout << "Species: " << flower.species()
    //               << ", Sepal Length: " << flower.sepallength()
    //               << ", Sepal Width: " << flower.sepalwidth()
    //               << ", Petal Length: " << flower.petallength()
    //               << ", Petal Width: " << flower.petalwidth() << std::endl;
    // }
}

void SerializeRapidjson::Serialize()
{
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

    writer.StartArray(); 

    for (const auto& flower : m_flowers) {
        writer.StartObject();
        writer.Key("sepalLength");
        writer.Double(flower.sepalLength);
        writer.Key("sepalWidth");
        writer.Double(flower.sepalWidth);
        writer.Key("petalLength");
        writer.Double(flower.petalLength);
        writer.Key("petalWidth");
        writer.Double(flower.petalWidth);
        writer.Key("species");
        writer.String(flower.species.c_str());
        writer.EndObject();
    }

    writer.EndArray(); 

    std::ofstream outFile("rapidjson_data.json");
    outFile << buffer.GetString();
    outFile.close();
}

void SerializeRapidjson::DeSerialize()
{
    std::ifstream inFile("rapidjson_data.json");
    if (!inFile) {
        std::cerr << "Error opening rapidjson_data file " << std::endl;
        return;
    }

    std::string jsonStr((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
    
    
    rapidjson::Document document;
    document.Parse(jsonStr.c_str());

    if (document.HasParseError()) {
        std::cerr << "JSON parsing error!" << std::endl;
        return;
    }


    for (const auto& item : document.GetArray()) {
        FlowerData data;
        data.sepalLength = item["sepalLength"].GetFloat();
        data.sepalWidth = item["sepalWidth"].GetFloat();
        data.petalLength = item["petalLength"].GetFloat();
        data.petalWidth = item["petalWidth"].GetFloat();
        data.species = item["species"].GetString();
        //test getbuffer() wjz
        std::cout << "Species: " << data.species
            << ", Sepal Length: " << data.sepalWidth
            << ", Sepal Width: " << data.sepalLength
            << ", Petal Length: " << data.petalLength
            << ", Petal Width: " << data.petalWidth << std::endl;
    }
}
