//
// Created by Kunming Yang on 2020-01-22.
//
#pragma once;

#ifndef PROJECT_GBMAPLOADER_H
#define PROJECT_GBMAPLOADER_H

#include "../GBMap/GBMap.h";
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class GBMapLoader;

class GBMapLoader
{
private:
    GBMap *map;
public:
    GBMapLoader();
    virtual ~GBMapLoader();
    virtual void readfromfile(std::string);
    void has_only_digits_err(const std::string, const std::string);
    void error_m();
    GBMap* getMap();
    void setMap(GBMap *GBMap_);
};



#endif //PROJECT_GBMAPLOADER_H
