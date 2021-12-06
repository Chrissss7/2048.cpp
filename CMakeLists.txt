cmake_minimum_required(VERSION 3.20)
project(2048)

set(CMAKE_CXX_STANDARD 17)

add_executable(2048 2048.cpp 2048-fonction.cpp 2048-test.cpp 2048.h ia.cpp iaa.cpp)
