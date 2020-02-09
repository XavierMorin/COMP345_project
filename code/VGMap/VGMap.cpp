#include "VGMap.h"
#include <iostream>

BuildingSlot::BuildingSlot() {
	
	
	adjacentBuildingSlots = new std::vector<BuildingSlot *>();
	Points = new int(0);
	BuildingBuilt = NULL;
	BuilingSlot_id = new int(0);
}

BuildingSlot::BuildingSlot(int Points_, int BuildingSlot_id_) {


	adjacentBuildingSlots = new std::vector<BuildingSlot *>();
	Points = new int(Points_);
	BuildingBuilt = NULL;
	BuilingSlot_id = new int(BuildingSlot_id_);
}

BuildingSlot::BuildingSlot(std::vector<BuildingSlot *> adjacentBuildingSlots_, int Points_, int BuildingSlot_id_) {
	
	
	*adjacentBuildingSlots = adjacentBuildingSlots_;
	Points = new int(Points_);
	BuildingBuilt = NULL;
	BuilingSlot_id = new int(BuildingSlot_id_);
}

BuildingSlot::~BuildingSlot() {
	delete Points;
	delete adjacentBuildingSlots;
	
}




std::vector<BuildingSlot *>& BuildingSlot::getAdjacentBuildingSlots() {
	return *adjacentBuildingSlots;
}

void BuildingSlot::setAdjacentbuildingSlots(std::vector<BuildingSlot *> adjBuildingSlot) {
	*adjacentBuildingSlots = adjBuildingSlot;
}

void BuildingSlot::addAdjacentBuildingSlot(BuildingSlot *BuildingSlot) {
	adjacentBuildingSlots->push_back(BuildingSlot);
}

bool BuildingSlot::isAdjacent(BuildingSlot *BuildingSlot) {
	for (int i = 0; i < adjacentBuildingSlots->size(); i++) {
		if (adjacentBuildingSlots->at(i) == BuildingSlot) {
			return true;
		}
	}
	return false;
}

int& BuildingSlot::getPoints() {
	return *Points;
}

void BuildingSlot::setPoints(int Points_) {
	*Points = Points_;
}

void BuildingSlot::print() {
	std::cout << "BuildingSlot : " << std::endl
		<< "\t Points : " << *Points << std::endl
		<< "\t adjacent building slots : " << std::endl;
	for (int i = 0; i < adjacentBuildingSlots->size(); i++) {
		std::cout << "\t\t - " << adjacentBuildingSlots->at(i)->getPoints() << std::endl;
	}
}


/** VGMap IMPLEMENTATION **/

VGMap::VGMap() {
	BuildingSlots = new std::vector<BuildingSlot *>();
	
}
VGMap::VGMap( std::string n) {
	BuildingSlots = new std::vector<BuildingSlot *>();
	name = new std::string(n);

}
VGMap::VGMap(std::vector<BuildingSlot *> *BuildingSlots_,std::string n) {
	BuildingSlots = BuildingSlots_;
	name = new std::string(n);
	
}

VGMap::~VGMap() {

	delete BuildingSlots;
}

std::vector<BuildingSlot *>& VGMap::getBuildingSlots() {
	return *BuildingSlots;
}

void VGMap::setBuildingSlots(std::vector<BuildingSlot *> BuildingSlots_) {
	*BuildingSlots = BuildingSlots_;
}

void VGMap::addBuildingSlot(BuildingSlot *BuildingSlot) {
	BuildingSlots->push_back(BuildingSlot);
}

bool VGMap::isConnectedGraph() {
	for (int i = 0; i < BuildingSlots->size(); i++) {
		for (int j = 0; j < BuildingSlots->at(i)->getAdjacentBuildingSlots().size(); j++) {
			if (!(BuildingSlots->at(i)->getAdjacentBuildingSlots().at(j)->isAdjacent(BuildingSlots->at(i)))) {
				//                std::cout << "BuildingSlots : " << BuildingSlots->at(i)->getAdjacentBuildingSlots().at(j)->getName() << " and " << BuildingSlots->at(i)->getName() << " are only connected one way." << std::endl;
				return false;
			}
		}
	}

	std::vector<BuildingSlot *> temp;
	for (int i = 0; i < BuildingSlots->size(); i++) {
		temp.insert(temp.end(), BuildingSlots->at(i)->getAdjacentBuildingSlots().begin(), BuildingSlots->at(i)->getAdjacentBuildingSlots().end());
	}
	std::sort(temp.begin(), temp.end());
	temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

	for (int i = 0; i < BuildingSlots->size(); i++) {
		if (std::find(temp.begin(), temp.end(), BuildingSlots->at(i)) == temp.end()) {
			//            std::cout << "BuildingSlot " << BuildingSlots->at(i)->getName() << " is not connected to the rest of the graph." << std::endl;
			return false;
		}
	}
	return true;
}







