//
// Created by Kunming Yang on 2020-01-22.
//

#include "GBMapLoader.h"
#include <iostream>

using namespace std;

GBMapLoader::GBMapLoader()
{
    map = new GBMap();
}

GBMapLoader::~GBMapLoader()
{
    delete map;
}

void GBMapLoader::readfromfile(std::string filename)
{
    //variable
    ifstream input(filename);           //file
    string line = "";                   //current line
    int slot_id = 0;                    //temp id of slot

    int flag = 0;


    string tile_upleft = "";
    string tile_upright = "";
    string tile_downleft = "";
    string tile_downright = "";



    //read file
    while (getline(input,line))
    {
        line.erase( remove(line.begin(), line.end(), '\r'), line.end());

        //empty line or comment line, do nothing
        if (line == "" || line.at(0) == ';')
        {
            // nothing happen
        }

        else
        {
            if (line.at(0) == '[' && line.at(line.length() - 1) == ']')
            {
                if (line == "[tile]")
                {
                    flag = 1;
                }
                else if (line == "[borders]")
                {
                    flag = 2;
                }
            }
        }
    }



}

void GBMapLoader::has_only_digits_err(const string, const string)
{

}

void GBMapLoader::error_m()
{
    cout << "Error - unexpected value was found in the program." << endl;
    //system("pause");
}

GBMap * GBMapLoader::getMap()
{
    return map;
}

void GBMapLoader::setMap(GBMap *GBMap_)
{
    this->map = GBMap_;
}