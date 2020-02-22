//
// Created by Kunming Yang on 2020-01-22.
//

#include "GBMap.h"
//#include "../Resources/Resources.h"
#include <iostream>
#include <vector>

using namespace std;

//Tile Section

Tile::Tile()
{
    upleft = new string ("");
    upright = new string ("");
    downleft = new string ("");
    downright = new string ("");
}

Tile::Tile(std::string upleft_, std::string upright_, std::string downleft_, std::string downright_)
{
    upleft = &upleft_;
    upright = &upright_;
    downleft = &downleft_;
    downright = &downright_;
}

Tile::~Tile()
{
    delete upleft;
    delete upright;
    delete downleft;
    delete downright;
}

void Tile::setUpleft(std::string upleft_)
{
    *upleft = upleft_;
}

void Tile::setUpright(std::string upright_)
{
    *upright = upright_;
}

void Tile::setDownleft(std::string downleft_)
{
    *downleft = downleft_;
}

void Tile::setDownright(std::string downright_)
{
    *downright = downright_;
}

//getters
string Tile::getUpleft()
{
    return *upleft;
}

string Tile::getUpright()
{
    return *upright;
}

string Tile::getDownleft()
{
    return *downleft;
}
string Tile::getDownright()
{
    return *downright;
}

//TileSlot section
//default
TileSlot::TileSlot()
{
    Tile_p = new Tile();
    TileSlot_id = new int(0);

}
//parameter
TileSlot::TileSlot(Tile Tile_, int TileSlot_id_)
{
    Tile_p = &Tile_;
    TileSlot_id = &TileSlot_id_;
}

//parameter
TileSlot::TileSlot(std::vector<TileSlot *> adjTilesSlots_, Tile Tile_, int TileSlot_id_)
{
    adjTiltSlots = &adjTilesSlots_;
    Tile_p = &Tile_;
    TileSlot_id = &TileSlot_id_;
}

//destructor
TileSlot::~TileSlot()
{
    delete adjTiltSlots;
    delete TileSlot_id;
    delete Tile_p;
}

Tile TileSlot::getTile()
{
    return *Tile_p;
}

void TileSlot::setTile(Tile Tile_)
{
    Tile_p = &Tile_;
}

TileSlot TileSlot::getTileSlot()
{
    return *TileSlot_p;
}

void TileSlot::setTileSlot(TileSlot TileSlot_)
{
    TileSlot_p = &TileSlot_;
}

bool TileSlot::isEmpty()
{
    if(this->getTile().getUpleft() == "")
        return true;
    else
        return false;
}


//adjacent TileSlot accessor method
std::vector<TileSlot *>& TileSlot::getAdjacentTileSlots()
{
    return *adjTiltSlots;
}

//adjacent TileSlot mutator method
void TileSlot::setAdjacentTileSlots(std::vector<TileSlot *> adjTileSlots_)
{
    adjTiltSlots = &adjTileSlots_;
}

//add TileSlot to adjacent TileSlot vector method
void TileSlot::addAdjacentTileSlot(TileSlot *TileSlots)
{
    adjTiltSlots->push_back(TileSlots);
}

//
int TileSlot::getTileSlotId()
{
    return *TileSlot_id;
}


//check if TileSlot is adjacent
bool TileSlot::isAdjacent(TileSlot *TileSlots)
{
    for (int i = 0; i < adjTiltSlots->size(); i++) {
        if (adjTiltSlots->at(i) == TileSlots)
        {
            return true;
        }
    }
    return false;
}

/**GBMap IMPLEMENTATION **/

GBMap::GBMap()
{
    TileSlots = new vector<TileSlot *>();
}

GBMap::GBMap(std::vector<TileSlot *> *TileSlots_)
{
    TileSlots = TileSlots_;

}

GBMap::~GBMap()
{
    delete TileSlots;
}

// Accessor method
std::vector<TileSlot *>& GBMap::getTileSlots()
{
    return *TileSlots;
}

// Mutator method
void GBMap::setTileSlots(std::vector<TileSlot *> TileSlots_)
{
    TileSlots = &TileSlots_;

}

// add TileSlot method
void GBMap::addTileSlot(TileSlot *TileSlots_)
{
    TileSlots->push_back(TileSlots_);
}


// check if a map is a connected graph
bool GBMap::isConnectedGraph()
{
    for (int i = 0; i < TileSlots->size(); i++) {
        for (int j = 0; j < TileSlots->at(i)->getAdjacentTileSlots().size(); j++) {
            if (!(TileSlots->at(i)->getAdjacentTileSlots().at(j)->isAdjacent(TileSlots->at(i)))) {
                //                std::cout << "TileSlots : " << TileSlots->at(i)->getAdjacentTileSlots().at(j)->getName() << " and " << TileSlots->at(i)->getName() << " are only connected one way." << std::endl;
                return false;
            }
        }
    }

    std::vector<TileSlot *> temp;
    for (int i = 0; i < TileSlots->size(); i++) {
        temp.insert(temp.end(), TileSlots->at(i)->getAdjacentTileSlots().begin(), TileSlots->at(i)->getAdjacentTileSlots().end());
    }
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < TileSlots->size(); i++) {
        if (std::find(temp.begin(), temp.end(), TileSlots->at(i)) == temp.end()) {
            //            std::cout << "BuildingSlot " << TileSlots->at(i)->getName() << " is not connected to the rest of the graph." << std::endl;
            return false;
        }
    }
    return true;
}

void GBMap::print()
{
    int *id = new int(0);
    Tile *temp = new Tile();

    for (int i = 0; i < map->getTileSlots().size(); i++)
    {
        *id = map->getTileSlots().at(i)->getTileSlotId();
        cout << "Id : " << id << endl;
        *temp = map->getTileSlots().at(i)->getTile();

        /* if there is tile inside, print tile information*/
        if (map->getTileSlots().at(i)->isEmpty())
        {
             cout << "Tile : " << endl;
             cout << "        " << "Upleft: " << temp->getUpleft() << endl;
             cout << "        " << "Upright: " << temp->getUpright() << endl;
             cout << "        " << "Downleft: " << temp->getDownleft() << endl;
             cout << "        " << "Downright: " << temp->getDownright() << endl;
        }
        /*if there is no tile inside, print empty */
        else
        {
            cout << "Empty Slot." << endl;
        }
    }
}


TileSlot GBMap::SearchById(GBMap* map_,int n)
{
    TileSlot *temp = new TileSlot();
    for (int i = 0; i < map->getTileSlots().size(); i++)
    {
        if(map->getTileSlots().at(i)->getTileSlotId() == n)
            *temp = map->getTileSlots().at(i)->getTileSlot();
    }

    if(temp->getTileSlotId() != 0)
    {
        return *temp;
    } else
    {
        cout << "Error: Did not find match!\nPlease try again!";
        return *temp;
    }

}
