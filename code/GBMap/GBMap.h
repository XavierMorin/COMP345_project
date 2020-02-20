//
// Created by Kunming Yang on 2020-01-22.
//
#pragma once

#ifndef PROJECT_GBMAP_H
#define PROJECT_GBMAP_H

#include <string>
#include <vector>
#include <algorithm>

class TileSlot;
class GBMap;

class TileSlot
{
public:
    //default
    TileSlot();
    //parameterized constructor
    TileSlot( Tile Tile_,
            int TileSlot_id);
    //parameterized constructor with adjacent TileSlots
    TileSlot(std::vector<TileSlot *> adjacentTilesSlots,
            Tile Tile_);
    //destructor
    ~TileSlot();

    //Accessors
    //Tile getter
    int &getTile();

    //Mutator
    void setTile();

    //adjacent TileSlot accessor method
    std::vector<TileSlot *>& getAdjacentTileSlots();

    //adjacent TileSlot mutator method
    void setAdjacentTileSlots(std::vector<TileSlot *> adjTileSlot);

    //add TileSlot to adjacent TileSlot vector method
    void addAdjacentTileSlot(TileSlot *TileSlot);

    //check if TileSlot is adjacent
    bool isAdjacent(TileSlot *TileSlot)

    void print();

private:
    //vector of all adjacent TileSlot
    std::vector<TileSlot *> *adjacentTiltSlots;

    //value of this slot
    int* TileSlot_id;
    Tile* Tile;

};


class GBMap{
public:
    //default constructor
    GBMap();
    //parameterized constructor
    GBMap(std::vector<TileSlot *> *TileSlot)
    //destructor
    ~GBMap();



    // PrintGBMap
    void printGBMap();
    // check if a map is a connected graph
    bool isConnectedGraph();
    // check if map contains duplicates
    bool containsDuplicates();
    // remove duplicates from map
    void removeDuplicates();
    //reset map
    void resetMap();

private:
    //vector containinf points to all circular spaces of the GBMap
    std::vector<TileSlot *> *TileSlot;

};


#endif //PROJECT_GBMAP_H
