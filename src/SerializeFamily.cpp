#include <iostream>
#include <fstream>
#include <vector>
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>

#include "SerializeFamily.h"
#include "iris_generated.h"
#include "include/iris.proto3.pb.h"
#include "include/articles_generated.h"
#include "include/articles.proto3.pb.h"

template <typename Func>
double measureTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}


void SerializeFlatBuffer::SerializeFlower()
{
    m_serializeTimeFlower  = measureTime([&]() {
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
    });
}

void SerializeFlatBuffer::DeSerializeFlower()
{
    m_deserializeTimeFlower  = measureTime([&]() {
        std::ifstream inFile("flatbuffer_data.bin", std::ios::binary);
        std::vector<char> buffer((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());


        const test::Flowers* flowers = nullptr;
        flowers = test::GetFlowers(buffer.data());
        //test getbuffer() wjz

        // for (const auto& flower : *flowers->flowers()) {
        //     std::cout << "Species: " << flower->species()->c_str()
        //               << ", Sepal Length: " << flower->sepalLength()
        //               << ", Sepal Width: " << flower->sepalWidth()
        //               << ", Petal Length: " << flower->petalLength()
        //               << ", Petal Width: " << flower->petalWidth() << std::endl;
        // }
        inFile.close();
    });
}

void SerializeFlatBuffer::SerializeArticles()
{
    m_serializeTimeArticle  = measureTime([&]() {
        flatbuffers::FlatBufferBuilder builder;
        std::vector<flatbuffers::Offset<ArticleData::Article>> serializedArticles;

        for (const auto& article : m_articles) {
            auto title = builder.CreateString(article.m_title);

            std::vector<flatbuffers::Offset<ArticleData::Paragraph>> serializedParagraphs;
            for (const auto& paragraph : article.m_paragraphs) {
                auto context = builder.CreateString(paragraph.m_context);

                std::vector<flatbuffers::Offset<ArticleData::QASData>> serializedQASData;
                for (const auto& qas : paragraph.m_qasData) {
                    auto qasId = builder.CreateString(qas.m_id);
                    auto question = builder.CreateString(qas.question);

                    std::vector<flatbuffers::Offset<ArticleData::CAnswer>> serializedAnswers;
                    for (const auto& answer : qas.m_answer) {
                        auto answerText = builder.CreateString(answer.m_text);
                        serializedAnswers.push_back(ArticleData::CreateCAnswer(builder, answer.m_anserStart, answerText));
                    }

                    serializedQASData.push_back(ArticleData::CreateQASData(
                        builder, qasId, question, builder.CreateVector(serializedAnswers)));
                }

                serializedParagraphs.push_back(ArticleData::CreateParagraph(
                    builder, context, builder.CreateVector(serializedQASData)));
            }

            serializedArticles.push_back(ArticleData::CreateArticle(
                builder, title, builder.CreateVector(serializedParagraphs)));
        }

        auto root = builder.CreateVector(serializedArticles);
        builder.Finish(root);

        std::ofstream outFile("flatbuffer_data_articale.bin", std::ios::binary);
        outFile.write(reinterpret_cast<const char*>(builder.GetBufferPointer()), builder.GetSize());
        outFile.close();
    });
}

void SerializeFlatBuffer::DeSerializeArticles()
{
    m_deserializeTimeArticle  = measureTime([&]() {
        std::ifstream inFile("flatbuffer_data_articale.bin", std::ios::binary);
        std::vector<char> buffer((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        
        const ArticleData::Articles* artical = nullptr;

        artical = ArticleData::GetArticles(buffer.data());
        
        inFile.close();
    });
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

void SerializeFamily::setArticles(std::vector<Articles> inArticles)
{
    m_articles.resize(inArticles.size());
    for (size_t i = 0; i < inArticles.size(); i++)
    {
        m_articles[i] = inArticles[i];
    }
}

void SerializeProtobuf::SerializeFlower()
{
    m_serializeTimeFlower  = measureTime([&]() {
        test1::Flowers protobufFlowers;
        std::ofstream outFile("protobuf_data.bin", std::ios::binary);

        for (const auto& data : m_flowers) {
                test1::Flower* flower = protobufFlowers.add_flowers();
                flower->set_sepallength(data.sepalLength);
                flower->set_sepalwidth(data.sepalWidth);
                flower->set_petallength(data.petalLength);
                flower->set_petalwidth(data.petalWidth);
                flower->set_species(data.species);
        }

    // uint8_t* temp = nullptr;
    // protobufFlowers.SerializeWithCachedSizesToArray(temp);


        protobufFlowers.SerializeToOstream(&outFile);


        outFile.close();
    });
}

void SerializeProtobuf::DeSerializeFlower()
{
    m_deserializeTimeFlower  = measureTime([&]() {
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
        inFile.close();
    });
}

void SerializeProtobuf::SerializeArticles()
{
    m_serializeTimeArticle  = measureTime([&]() {
        test_art::Articles protoArticles;
        std::ofstream outFile("flatbuffer_data_articale.bin", std::ios::binary);

        for (const auto& article : m_articles) {
            test_art::Article* protoarticle = protoArticles.add_article();
            protoarticle->set_title(article.m_title);
            auto* protoArticleItem = protoarticle->add_paragraphs();

            for (const auto& paragraph : article.m_paragraphs) {
                auto* protoParagraph = protoArticleItem->add_qasdata();
                protoArticleItem->set_context(paragraph.m_context);

                for (const auto& qas : paragraph.m_qasData) {
                    auto* protoQAS = protoArticleItem->add_qasdata();
                    protoQAS->set_id(qas.m_id);
                    protoQAS->set_question(qas.question);

                    for (const auto& answer : qas.m_answer) {
                        auto* protoAnswer = protoQAS->add_answers();
                        protoAnswer->set_answer_start(answer.m_anserStart);
                        protoAnswer->set_text(answer.m_text);
                    }
                }
            }
        }
        protoArticles.SerializeToOstream(&outFile);


        outFile.close();
    });
}

void SerializeProtobuf::DeSerializeArticles()
{
    m_deserializeTimeArticle  = measureTime([&]() {
        test_art::Article protoArticle;
        std::ifstream inFile("flatbuffer_data_articale.bin", std::ios::binary);

            protoArticle.ParseFromIstream(&inFile);

        inFile.close();
    });
}

void SerializeRapidjson::SerializeFlower()
{
    m_serializeTimeFlower  = measureTime([&]() {
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
    });
}

void SerializeRapidjson::DeSerializeFlower()
{
    m_deserializeTimeFlower  = measureTime([&]() {
        std::ifstream inFile("rapidjson_data.json");

        std::string jsonStr((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        
        
        rapidjson::Document document;

        document.Parse(jsonStr.c_str());

    // for (const auto& item : document.GetArray()) {
    //     FlowerData data;
    //     data.sepalLength = item["sepalLength"].GetFloat();
    //     data.sepalWidth = item["sepalWidth"].GetFloat();
    //     data.petalLength = item["petalLength"].GetFloat();
    //     data.petalWidth = item["petalWidth"].GetFloat();
    //     data.species = item["species"].GetString();
    //     //test getbuffer() wjz
    //     // std::cout << "Species: " << data.species
    //     //     << ", Sepal Length: " << data.sepalWidth
    //     //     << ", Sepal Width: " << data.sepalLength
    //     //     << ", Petal Length: " << data.petalLength
    //     //     << ", Petal Width: " << data.petalWidth << std::endl;
    // }
        inFile.close();
    });

}

void SerializeRapidjson::SerializeArticles()
{
    m_serializeTimeArticle  = measureTime([&]() {
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

        writer.StartArray(); 
        for (const auto& article : m_articles) {
            writer.StartObject();
            writer.Key("title");
            writer.String(article.m_title.c_str());
            writer.Key("paragraphs");
            writer.StartArray(); 
            for (const auto& paragraph : article.m_paragraphs)
            {
                writer.StartObject();
                writer.Key("context");
                writer.String(paragraph.m_context.c_str());
                writer.Key("qas");
                writer.StartArray(); 
                for (const auto& qasData : paragraph.m_qasData)
                {
                    writer.StartObject();
                    writer.Key("answers");
                    writer.StartArray(); 
                    for (const auto& answer : qasData.m_answer)
                    {
                        writer.StartObject();
                        writer.Key("answer_start");
                        writer.Int64(answer.m_anserStart);
                        writer.Key("text");
                        writer.String(answer.m_text.c_str());
                        writer.EndObject();
                    }
                    writer.EndArray();
                    writer.Key("question");
                    writer.String(qasData.question.c_str());
                    writer.Key("id");
                    writer.String(qasData.m_id.c_str());
                    writer.EndObject();
                }
                
                writer.EndArray(); 
                writer.EndObject();
            }
            writer.EndArray(); 
            writer.EndObject();
        }
        writer.EndArray(); 

        std::ofstream outFile("rapidjson_data.json");
        outFile << buffer.GetString();
        outFile.close();
    });
}

void SerializeRapidjson::DeSerializeArticles()
{
    m_deserializeTimeArticle  = measureTime([&]() {
        std::ifstream inFile("rapidjson_data.json");


        std::string jsonStr((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());
        
        
        rapidjson::Document document;

        document.Parse(jsonStr.c_str());


    for (const auto& articleJson : document.GetArray()) {
        Articles article;

        article.m_title = articleJson["title"].GetString();
        for (const auto& paragraphJson : articleJson["paragraphs"].GetArray()) {
                Paragraphs paragraph;
                paragraph.m_context = paragraphJson["context"].GetString();
                    for (const auto& qasJson : paragraphJson["qas"].GetArray()) {
                        QASData qas;
                        qas.m_id = qasJson["id"].GetString();
                        qas.question = qasJson["question"].GetString();

                        for (const auto& answerJson : qasJson["answers"].GetArray()) {
                            CAnswer answer;
                            answer.m_anserStart = answerJson["answer_start"].GetInt64();
                            answer.m_text = answerJson["text"].GetString();
                            qas.m_answer.push_back(answer);
                        }

                        paragraph.m_qasData.push_back(qas);
                    }

                article.m_paragraphs.push_back(paragraph);
            }

        m_articles.push_back(article);
    }
    inFile.close();
    });
}
