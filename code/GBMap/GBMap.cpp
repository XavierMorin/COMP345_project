//
// Created by Kunming Yang on 2020-01-22.
//

#include "GBMap.h"
#include "../Resources/Resources.h"
#include <iostream>
Tile::Tile()
{
    *top_left = "";
    *top_right = "";
    *bottom_left = "";
    *bottom_right = "";
}

Tile::Tile(
        std::string top_left_,
        std::string top_right_,
        std::string bottom_left_,
        std::string bottom_right_)
{
    *top_left = top_left_;
    *top_right = top_right_;
    *bottom_left = bottom_left_;
    *bottom_right = bottom_right_;
}

TileSlot::TileSlot()
{
    *adjacentTiltSlots = new std::vector<TileSlot *>();
    *Tile = new Tile();
    *TileSlot_id = new int(0);
}

TileSlot::TileSlot(Tile Tile_
        int TileSlot_id_){

    *adjacentTiltSlots = new std::vector<TileSlot *>();
    *Tile = Tile_;
    *TileSlot_id = new int(TileSlot_id_);
}

TileSlot::TileSlot(
        std::vector<TileSlot *> adjacentTileSlots_,
        Tile Tile_,
        int TileSlot_id_)
        {

    *adjacentTiltSlots = adjacentTileSlots_;
    *Tile = Tile_;
    *TileSlot_id = new int(TileSlot_id_)
}

TileSlot::~TileSlot()
{
    delete adjacentTiltSlots;
    delete TileSlot_id;
    delete Tile;
}

std::vector<TileSlot* > &TileSlot::getAdjacentTileSlots()
{
    return *adjacentTiltSlots;
}

void TileSlot::setAdjacentTileSlots(std::vector<TileSlot *> adjTileSlot)
{
    *adjacentTiltSlots = adjTileSlot;
}

void TileSlot::addAdjacentTileSlot(TileSlot *TileSlot)
{
    adjacentTiltSlots -> push_back(TileSlot);
}

bool TileSlot::isAdjacent(TileSlot *TileSlot)
{
    for (int i = 0; i < adjacentTiltSlots->size(); ++i)
    {
        if(adjacentTiltSlots->at(i) == TileSlot) {
            return true;
        }
    }
    return false;
}




/** GBMap IMPLEMENTATION **/

GBMap::GBMap(){

}