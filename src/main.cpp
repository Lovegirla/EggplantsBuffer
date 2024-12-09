#include <iostream>
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include <flatbuffers/flatbuffers.h>
#include <tyl_generated.h>

#include "datastruct.h"
#include "iris_generated.h"
#include "SerializeFamily.h"
 

void loadJsonData(const std::string& filename, std::vector<FlowerData>& flowers) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    nlohmann::json j;
    inFile >> j;  

    for (const auto& item : j) {
        FlowerData data;
        data.sepalLength = item["sepalLength"];
        data.sepalWidth = item["sepalWidth"];
        data.petalLength = item["petalLength"];
        data.petalWidth = item["petalWidth"];
        data.species = item["species"];

        flowers.push_back(data); 
    }
}

void testLoadJson()
{
    std::vector<FlowerData> flowers;
    SerializeFlatBuffer myFlatBuffer;
    SerializeProtobuf myProtoBuf;
    SerializeRapidjson myRapidjson;
    loadJsonData("/home/notebook/EggplantsBuffer/benchmark/iris.json", flowers);


    std::cout <<"*************EggplantsBuffer*************"<<std::endl; 
    std::cout <<"*************开始打印json文件*************"<<std::endl; 
    for (const auto& flower : flowers) {
        std::cout << "Species: " << flower.species
                  << ", Sepal Length: " << flower.sepalLength
                  << ", Sepal Width: " << flower.sepalWidth
                  << ", Petal Length: " << flower.petalLength
                  << ", Petal Width: " << flower.petalWidth << std::endl;
    }
    std::cout <<"*************EggplantsBuffer*************"<<std::endl; 
    std::cout <<"*************打印完成*************"<<std::endl; 
    myFlatBuffer.setFlowers(flowers);
    myFlatBuffer.Serialize();
    myFlatBuffer.DeSerialize();

    myProtoBuf.setFlowers(flowers);
    myProtoBuf.Serialize();
    myProtoBuf.DeSerialize();

    myRapidjson.setFlowers(flowers);
    myRapidjson.Serialize();
    myRapidjson.DeSerialize();

    std::cout<<"*************test results*************"<<std::endl;
    std::cout<<"benmark name : iris 9 k"<<std::endl;
    std::cout<<"flatbuffer"<< "序列化时间："<<myFlatBuffer.m_serializeTime << "反序列化时间："<<myFlatBuffer.m_deserializeTime<<std::endl;
    std::cout<<"protobuffer"<< "序列化时间："<<myProtoBuf.m_serializeTime<< "反序列化时间：" << myProtoBuf.m_deserializeTime<<std::endl;
    std::cout<<"rapidjson"<< "序列化时间："<<myRapidjson.m_serializeTime<< "反序列化时间：" << myRapidjson.m_deserializeTime<<std::endl;
}

template <typename Func>
double measureTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}



void testSerialization() {

    testLoadJson();
    // std::string name = "Example";
    // int id = 1234;
    // std::vector<int> values = {1, 2, 3, 4, 5};

    // 测试 FlatBuffers
    // {
    //     flatbuffers::FlatBufferBuilder builder;
    //     auto nameOffset = builder.CreateString(name);
    //     auto valuesOffset = builder.CreateVector(values);
    //     auto flatBufferData = CreateTYL(builder, id, nameOffset, valuesOffset);
    //     // builder.Finish(flatBufferData);


    //     double serializeTime = measureTime([&]() {
    //         // builder.Clear();
    //         builder.Finish(flatBufferData);
    //     });
    //     std::vector<uint8_t> serializedData(builder.GetBufferPointer(), 
    //                                 builder.GetBufferPointer() + builder.GetSize());
    //     std::cout << "FlatBuffers Serialization Time: " << serializeTime << " ms\n";
    //     std::cout << "FlatBuffers Serialized Size: " << serializedData.size() << " bytes\n";

    //     double deserializeTime = measureTime([&]() {
    //         auto deserializedObject = GetTYL(serializedData.data());
    //         (void)deserializedObject;
    //     });
    //     std::cout << "FlatBuffers Deserialization Time: " << deserializeTime << " ms\n";
    // }
}
int main()
{
    testSerialization();
    return 0;
}
