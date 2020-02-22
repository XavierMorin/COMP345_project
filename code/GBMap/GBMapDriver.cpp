//
// Created by Kunming Yang on 2020-02-02.
//

#include "GBMap.h"
#include <iostream>

using namespace std;

int main()
{

    TileSlot *TileSlot11 = new TileSlot(Tile(), 11);
    TileSlot *TileSlot12 = new TileSlot(Tile(), 12);
    TileSlot *TileSlot13 = new TileSlot(Tile(), 13);

    TileSlot *TileSlot21 = new TileSlot(Tile(), 21);
    TileSlot *TileSlot22 = new TileSlot(Tile(), 22);
    TileSlot *TileSlot23 = new TileSlot(Tile(), 23);

    TileSlot *TileSlot31 = new TileSlot(Tile(), 31);
    TileSlot *TileSlot32 = new TileSlot(Tile(), 32);
    TileSlot *TileSlot33 = new TileSlot(Tile(), 33);


    TileSlot11->addAdjacentTileSlot(TileSlot12);
    TileSlot11->addAdjacentTileSlot(TileSlot21);

    TileSlot12->addAdjacentTileSlot(TileSlot11);
    TileSlot12->addAdjacentTileSlot(TileSlot23);
    TileSlot12->addAdjacentTileSlot(TileSlot32);

    TileSlot13->addAdjacentTileSlot(TileSlot12);
    TileSlot13->addAdjacentTileSlot(TileSlot23);

    GBMap* map = new GBMap();

    map->addTileSlot(TileSlot11);
    map->addTileSlot(TileSlot12);
    map->addTileSlot(TileSlot13);

    map->addTileSlot(TileSlot21);
    map->addTileSlot(TileSlot22);
    map->addTileSlot(TileSlot23);

    map->addTileSlot(TileSlot31);
    map->addTileSlot(TileSlot32);
    map->addTileSlot(TileSlot33);

    map->print();

}
