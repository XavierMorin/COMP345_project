//
// Created by Kunming Yang on 2020-01-22.
//
#pragma once

#ifndef PROJECT_RESOURCES_H
#define PROJECT_RESOURCES_H

#include <string>

class Tile;

class Tile
{
public:
    //default
    Tile();
    //parameterized constructor
    Tile(std::string top_left,
         std::string top_right,
         std::string bottom_left,
         std::string bottom_right);

private:
    std::string* top_left;
    std::string* top_right;
    std::string* bottom_left;
    std::string* bottom_right;

};

class Resources
        {

};


#endif //PROJECT_RESOURCES_H
