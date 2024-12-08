cmake_minimum_required(VERSION 3.22)

project(EggplantsBuffers LANGUAGES CXX)

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/include 
${PROJECT_SOURCE_DIR}/VegetablesBuffer ${PROJECT_SOURCE_DIR}/VegetablesBuffer/protoc ${PROJECT_SOURCE_DIR}/VegetablesBuffer/protoc/include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable( EGGPLANTSBUFFER src/iris.proto3.pb.cc src/main.cpp src/tyl.proto3.pb.cc src/SerializeFamily.cpp src/datastruct.cpp)
target_link_libraries(EGGPLANTSBUFFER PRIVATE ${PROTOBUF_LIBRARIES})