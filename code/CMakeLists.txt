cmake_minimum_required(VERSION 3.15)
project(code)

set(CMAKE_CXX_STANDARD 14)

include_directories(GBMap)
include_directories(Resources)

add_executable(code
        GBMap/GBMap.cpp
        GBMap/GBMap.h
        GBMap/GBMapDriver.cpp
        MapLoader/GBMapLoader.cpp
        MapLoader/GBMapLoader.h
        Resources/Resources.cpp
        Resources/Resources.h)
