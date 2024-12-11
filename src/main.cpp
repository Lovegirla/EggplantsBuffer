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

#include "include/MyTest.h"


void testSerialization() {

    std::string name = "Example";
    int id = 1234;
    std::vector<int> values = {1, 2, 3, 4, 5};

    //测试 FlatBuffers
    {
        flatbuffers::FlatBufferBuilder builder;
        auto nameOffset = builder.CreateString(name);
        auto valuesOffset = builder.CreateVector(values);
        auto flatBufferData = CreateTYL(builder, id, nameOffset, valuesOffset);
        // builder.Finish(flatBufferData);
        builder.Finish(flatBufferData);

        std::vector<uint8_t> serializedData(builder.GetBufferPointer(), 
                                    builder.GetBufferPointer() + builder.GetSize());
        std::cout << "FlatBuffers Serialized Size: " << serializedData.size() << " bytes\n";

        auto deserializedObject = GetTYL(serializedData.data());
    }
}
int main()
{
    testSerialization();
    MyTest mytest;
    mytest.TestFlower();
    mytest.TestArticles();
    return 0;
}
