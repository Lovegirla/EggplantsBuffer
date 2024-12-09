#pragma onece
#include <vector>
#include "datastruct.h"

class SerializeFamily
{
public:
    SerializeFamily();
    ~SerializeFamily();

    virtual void Serialize() = 0;
    virtual void DeSerialize() = 0;
    void PrintFlowers();
    void setFlowers(std::vector<FlowerData> inFlowers);
public:
    double m_serializeTime;
    double m_deserializeTime;
protected:
    std::vector<FlowerData> m_flowers;
};

class SerializeFlatBuffer : public SerializeFamily
{
public: 
    void Serialize();
    void DeSerialize();
};

class SerializeProtobuf : public SerializeFamily
{
public:
    void Serialize();
    void DeSerialize();
};

class SerializeRapidjson : public SerializeFamily
{
public:
    void Serialize();
    void DeSerialize();
};