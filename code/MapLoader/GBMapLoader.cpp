//
// Created by Kunming Yang on 2020-01-22.
//

#include "GBMapLoader.h"
#include "../Resources//Resources.h"
#include <sstream>
#include <algorithm>

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
    string word = "";

    int flag = 0;                       //flags
    int i = 0;                          //counter


    //Tile
    int tile_id = 0;
    string upleft = "";
    string upright = "";
    string downleft = "";
    string downright = "";

    //Boarder
    int id = 0,
        id_left = 0,
        id_top = 0,
        id_right = 0,
        id_down = 0;


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
                //set flag = 1, when read tile.
                if (line == "[tile]")
                {
                    if (flag == 0)
                        flag = 1;
                    else
                        error_m();
                }
                //set flag = 2, when read boarders.
                else if (line == "[borders]")
                {
                    if (flag == 1)
                        flag = 2;
                    else
                        error_m();
                }

                else
                {
                    flag = 0;
                }
            } else
            {
                istringstream iss(line);

                //Tile Section
                //11 sheelp stone sheep wheat; tileid - upleft - upright - downleft - downright
                if (flag == 1)
                {
                    iss >> tile_id;
                    iss >> upleft;
                    iss >> upright;
                    iss >> downleft;
                    iss >> downright;
                    for (int j = 0; j < map->getTileSlots().size(); j++)
                    {
                        if(map->getTileSlots().at(j)->getTileSlotId() == tile_id)
                        {
                            error_m();
                        }
                    }
                    TileSlot(Tile(Tile::sToTypes(upleft),Tile::sToTypes(upright),
                            Tile::sToTypes(downleft),Tile::sToTypes(downright)), tile_id);
                }

                //Boarders section
                //11 12 21 ; tileid - adjacent tiles
                else if (flag == 2)
                {
                    iss >> id;
                    iss >> id_left;
                    iss >> id_top;
                    iss >> id_right;
                    iss >> id_down;

                    map->getTileSlots().at(id)->addAdjacentTileSlot(map->getTileSlots().at(id_left));
                    map->getTileSlots().at(id)->addAdjacentTileSlot(map->getTileSlots().at(id_top));
                    map->getTileSlots().at(id)->addAdjacentTileSlot(map->getTileSlots().at(id_right));
                    map->getTileSlots().at(id)->addAdjacentTileSlot(map->getTileSlots().at(id_down));



                }
            }
        }
    }
    input.close();


}

void GBMapLoader::error_m()
{
    cout << "Error - unexpected value was found in the program." << endl;
    //system("pause");
    exit(1);
}

GBMap * GBMapLoader::getMap()
{
    return map;
}

void GBMapLoader::setMap(GBMap *GBMap_)
{
    this->map = GBMap_;
}
Tile::Types Tile::sToTypes(std::string str)
{
    if (str == "sheep")
        return sheep;
    else if (str == "wheet")
        return wheet;
    else if (str == "stone")
        return stone;
    else if (str == "timber")
        return timber;
}