#pragma once
#include <string>

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

