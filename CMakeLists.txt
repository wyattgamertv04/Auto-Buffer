cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include($ENV{GEODE_SDK}/cmake/GeodeFile.cmake)

project(AutoBuffer VERSION 1.0.0)

add_geode_mod(
    AutoBuffer
    mod.json
    src/main.cpp
)
