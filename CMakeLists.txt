cmake_minimum_required(VERSION 3.16)
project(patterns_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(factory_method src/factory_method.cpp)
add_executable(abstract_factory src/abstract_factory.cpp)
add_executable(builder src/builder.cpp)
add_executable(prototype src/prototype.cpp)