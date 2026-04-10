cmake_minimum_required(VERSION 3.14)

project(lte_analyzer)

set(CMAKE_CXX_STANDARD 17)

add_executable(lte_analyzer
    src/main.cpp
    src/readerIQ.cpp
    src/fft.cpp

)

target_include_directories(lte_analyzer PRIVATE include)