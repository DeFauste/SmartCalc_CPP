cmake_minimum_required(VERSION 3.27)
project(CPP3_SmartCalc_v2_0_1)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(
        CPP3_SmartCalc_v2_0_1
        src/main.cpp
        src/Model/CalculatorModel.h
        src/Model/CalculatorModel.cpp
        src/UnitTest/calculator_test.cpp
)
