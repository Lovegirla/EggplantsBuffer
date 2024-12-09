#include "include/MyTest.h"
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

void loadIrisData(const std::string& filename, std::vector<FlowerData>& flowers) {
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

void loadQAData(const std::string& filename, std::vector<Articles>& inArticle) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    nlohmann::json j;
    inFile >> j;

    for (const auto& articleJson : j["data"]) {
        Articles article;
        article.m_title = articleJson.at("title").get<std::string>();

        for (const auto& paragraphJson : articleJson.at("paragraphs")) {
            Paragraphs paragraph;
            paragraph.m_context = paragraphJson.at("context").get<std::string>();

            for (const auto& qasJson : paragraphJson.at("qas")) {
                QASData qas;
                qas.m_id = qasJson.at("id").get<std::string>();
                qas.question = qasJson.at("question").get<std::string>();

                for (const auto& answerJson : qasJson.at("answers")) {
                    CAnswer answer;
                    answer.m_anserStart = answerJson.at("answer_start").get<int>();
                    answer.m_text = answerJson.at("text").get<std::string>();
                    qas.m_answer.push_back(answer);
                }

                paragraph.m_qasData.push_back(qas);
            }

            article.m_paragraphs.push_back(paragraph);
        }

        inArticle.push_back(article);
    }
}

void MyTest::TestFlower()
{
    std::vector<FlowerData> flowers;

    SerializeFlatBuffer myFlatBuffer;
    SerializeProtobuf myProtoBuf;
    SerializeRapidjson myRapidjson;
    loadIrisData("/home/notebook/EggplantsBuffer/benchmark/iris.json", flowers);


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
    myFlatBuffer.SerializeFlower();
    myFlatBuffer.DeSerializeFlower();

    myProtoBuf.setFlowers(flowers);
    myProtoBuf.SerializeFlower();
    myProtoBuf.DeSerializeFlower();

    myRapidjson.setFlowers(flowers);
    myRapidjson.SerializeFlower();
    myRapidjson.DeSerializeFlower();

    std::cout<<"*************test results*************"<<std::endl;
    std::cout<<"benmark name : iris 16 k"<<std::endl;
    std::cout<<"flatbuffer"<< "序列化时间(ms):"<<myFlatBuffer.m_serializeTimeFlower << "反序列化时间(ms):"<<myFlatBuffer.m_deserializeTimeFlower<<std::endl;
    std::cout<<"protobuffer"<< "序列化时间(ms):"<<myProtoBuf.m_serializeTimeFlower<< "反序列化时间(ms):" << myProtoBuf.m_deserializeTimeFlower<<std::endl;
    std::cout<<"rapidjson"<< "序列化时间(ms):"<<myRapidjson.m_serializeTimeFlower<< "反序列化时间(ms):" << myRapidjson.m_deserializeTimeFlower<<std::endl;
}

void MyTest::TestArticles()
{
    
    SerializeFlatBuffer myFlatBuffer;
    SerializeProtobuf myProtoBuf;
    SerializeRapidjson myRapidjson;
    std::vector<Articles> articles;
    loadQAData("/home/notebook/EggplantsBuffer/benchmark/train-v1.1.json",articles);
    myFlatBuffer.setArticles(articles);
    myFlatBuffer.SerializeArticles();
    myFlatBuffer.DeSerializeArticles();

    myProtoBuf.setArticles(articles);
    myProtoBuf.SerializeArticles();
    myProtoBuf.DeSerializeArticles();

    myRapidjson.setArticles(articles);
    myRapidjson.SerializeArticles();
    myRapidjson.DeSerializeArticles();
        std::cout<<"*************test results*************"<<std::endl;
    std::cout<<"benmark name : train-v1 29.58 M"<<std::endl;
    std::cout<<"flatbuffer"<< "序列化时间(ms):"<<myFlatBuffer.m_serializeTimeArticle << "反序列化时间(ms):"<<myFlatBuffer.m_deserializeTimeArticle<<std::endl;
    std::cout<<"protobuffer"<< "序列化时间(ms):"<<myProtoBuf.m_serializeTimeArticle<< "反序列化时间(ms):" << myProtoBuf.m_deserializeTimeArticle<<std::endl;
    std::cout<<"rapidjson"<< "序列化时间(ms):"<<myRapidjson.m_serializeTimeArticle<< "反序列化时间(ms):" << myRapidjson.m_deserializeTimeArticle<<std::endl;
}
