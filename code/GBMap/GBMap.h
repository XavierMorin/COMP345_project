//
// Created by Kunming Yang on 2020-01-22.
//
#pragma once

#ifndef PROJECT_GBMAP_H
#define PROJECT_GBMAP_H

#include "../Resources/Resources.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

class TileSlot;
TileSlot();

class GBMap;

class TileSlot
{
public:
    //default
    TileSlot();
    //parameterized constructor
    TileSlot(Tile Tile_,int TileSlot_id_);
    //parameterized constructor with adjacent TileSlots
    TileSlot(std::vector<TileSlot *> *adjTilesSlots_,Tile Tile_,int TileSlot_id_);
    //destructor
    ~TileSlot();

    Tile& getTile();

    void setTile(Tile Tile_);


    //adjacent TileSlot accessor method
    std::vector<TileSlot *>& getAdjacentTileSlots();

    //adjacent TileSlot mutator method
    void setAdjacentTileSlots(std::vector<TileSlot *> adjTileSlot);

    //add TileSlot to adjacent TileSlot vector method
    void addAdjacentTileSlot(TileSlot *TileSlot);

    //get Tile Id
    int getTileSlotId();

    //check if TileSlot is adjacent
    bool isAdjacent(TileSlot *TileSlot);

    void print();

private:
    //vector of all adjacent TileSlot
    std::vector<TileSlot *> *adjTiltSlots;
    //value of this slot
    Tile* Tile_p;
    int *TileSlot_id;
    TileSlot* left;
    TileSlot* up;
    TileSlot* right;
    TileSlot* down;


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

    void print(GBMap map);
private:
    //vector containinf points to all circular spaces of the GBMap
    std::vector<TileSlot *> *TileSlots;


};


#endif //PROJECT_GBMAP_H
