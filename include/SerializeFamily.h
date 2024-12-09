#pragma onece
#include <vector>
#include "datastruct.h"

class SerializeFamily
{
public:
    SerializeFamily();
    ~SerializeFamily();

    virtual void SerializeFlower() = 0;
    virtual void DeSerializeFlower() = 0;
    virtual void SerializeArticles() = 0;
    virtual void DeSerializeArticles() = 0;
    void PrintFlowers();
    void setFlowers(std::vector<FlowerData> inFlowers);
    void setArticles(std::vector<Articles> inArticles);
public:
    double m_serializeTimeFlower;
    double m_deserializeTimeFlower;
    double m_serializeTimeArticle;
    double m_deserializeTimeArticle;
protected:
    std::vector<FlowerData> m_flowers;
    std::vector<Articles> m_articles;
};

class SerializeFlatBuffer : public SerializeFamily
{
public: 
    void SerializeFlower();
    void DeSerializeFlower();
    void SerializeArticles();
    void DeSerializeArticles();
};

class SerializeProtobuf : public SerializeFamily
{
public:
    void SerializeFlower();
    void DeSerializeFlower();
    void SerializeArticles();
    void DeSerializeArticles();
};

class SerializeRapidjson : public SerializeFamily
{
public:
    void SerializeFlower();
    void DeSerializeFlower();
    void SerializeArticles();
    void DeSerializeArticles();
};