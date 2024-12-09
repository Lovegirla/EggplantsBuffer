#pragma once
#include <string>
#include <vector>

class FlowerData {
public: 
    FlowerData();
    ~FlowerData();
public:
    float sepalLength;
    float sepalWidth;
    float petalLength;
    float petalWidth;
    std::string species;
};

class CAnswer
{
public:
    int m_anserStart;
    std::string m_text;
};

class QASData
{
public:
    std::string m_id;
    std::string question;
    std::vector<CAnswer> m_answer;
};

class Paragraphs
{
public:
    std::vector<QASData> m_qasData;
    std::string m_context;
};

class Articles
{
public:
    std::string m_title;
    std::vector<Paragraphs> m_paragraphs;
};

