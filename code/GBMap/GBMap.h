//
// Created by Kunming Yang on 2020-01-22.
//
#pragma once

#ifndef PROJECT_GBMAP_H
#define PROJECT_GBMAP_H

//#include "../Resources/Resources.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

class TileSlot;

class GBMap;

class Tile
{
public:
    Tile();
    Tile(std::string upleft_, std::string upright_, std::string downleft_, std::string downright_);
    ~Tile();

    //setter
    void setUpleft(std::string upleft_);
    void setUpright(std::string upright_);
    void setDownleft(std::string downleft_);
    void setDownright(std::string downright_);

    //getter
    std::string getUpleft();
    std::string getUpright();
    std::string getDownleft();
    std::string getDownright();
private:
    std::string* upleft;
    std::string* upright;
    std::string* downleft;
    std::string* downright;

};

class TileSlot
{
public:
    //default
    TileSlot();
    //parameterized constructor
    TileSlot(Tile Tile_,int TileSlot_id_);
    //parameterized constructor with adjacent TileSlots
    TileSlot(std::vector<TileSlot *> adjTilesSlots_,Tile Tile_,int TileSlot_id_);
    //destructor
    ~TileSlot();

    Tile getTile();

    void setTile(Tile Tile_);

    //get Tile Id
    int getTileSlotId();

    //getTileSlot
    TileSlot getTileSlot();

    void setTileSlot(TileSlot TileSlot_);

    bool isEmpty();

    //adjacent TileSlot accessor method
    std::vector<TileSlot *>& getAdjacentTileSlots();

    //adjacent TileSlot mutator method
    void setAdjacentTileSlots(std::vector<TileSlot *> adjTileSlot);

    //add TileSlot to adjacent TileSlot vector method
    void addAdjacentTileSlot(TileSlot *TileSlot);

    //check if TileSlot is adjacent
    bool isAdjacent(TileSlot *TileSlot);

    void print();

private:
    //vector of all adjacent TileSlot
    std::vector<TileSlot *> *adjTiltSlots;
    //value of this slot
    Tile* Tile_p;
    int *TileSlot_id;
    TileSlot* TileSlot_p;


};


class GBMap{
public:
    //default constructor
    GBMap();
    //parameterized constructor
    GBMap(std::vector<TileSlot *> *TileSlots_);
    //destructor
    ~GBMap();

    // Accessor method
    std::vector<TileSlot *>& getTileSlots();

    // Mutator method
    void setTileSlots(std::vector<TileSlot *> TileSlot_);

    // add TileSlot method
    void addTileSlot(TileSlot *TileSlot_ptr_);

    // check if a map is a connected graph
    bool isConnectedGraph();

    void print();

    TileSlot SearchById(GBMap* map_,int n);
private:
    //vector containinf points to all circular spaces of the GBMap
    std::vector<TileSlot *> *TileSlots;
    GBMap *map;


};


#endif //PROJECT_GBMAP_H
