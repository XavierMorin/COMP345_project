#include "VGMap.h"
#include <iostream>

/** BuildingSlot IMPLEMENTATION **/

BuildingSlot::BuildingSlot() {


	adjacentBuildingSlots = new std::vector<BuildingSlot *>();
	Points = new int(0);
	BuildingBuilt = NULL;
	BuildingSlot_id = new int(0);
}

BuildingSlot::BuildingSlot(int Points_, int BuildingSlot_id_) {


	adjacentBuildingSlots = new std::vector<BuildingSlot *>();
	Points = new int(Points_);
	BuildingBuilt = NULL;
	BuildingSlot_id = new int(BuildingSlot_id_);
}

BuildingSlot::BuildingSlot(std::vector<BuildingSlot *> adjacentBuildingSlots_, int Points_, int BuildingSlot_id_) {


	*adjacentBuildingSlots = adjacentBuildingSlots_;
	Points = new int(Points_);
	BuildingBuilt = NULL;
	BuildingSlot_id = new int(BuildingSlot_id_);
}

BuildingSlot::~BuildingSlot() {
	delete Points;
	delete adjacentBuildingSlots;
	delete BuildingSlot_id;
	delete BuildingBuilt;

}




std::vector<BuildingSlot *>& BuildingSlot::getAdjacentBuildingSlots() {
	return *adjacentBuildingSlots;
}

void BuildingSlot::setAdjacentbuildingSlots(std::vector<BuildingSlot *> adjBuildingSlot) {
	*adjacentBuildingSlots = adjBuildingSlot;
}

void BuildingSlot::addAdjacentBuildingSlots(BuildingSlot *BuildingSlot) {
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
int& BuildingSlot::getBuildingSlot_id() {
	return *BuildingSlot_id;
}

void BuildingSlot::setPoints(int Points_) {
	*Points = Points_;
}

Building& BuildingSlot::getBuilding() {
	return *BuildingBuilt;
}

void BuildingSlot::setBuilding(Building b) {
	*BuildingBuilt =b;
}

void BuildingSlot::print() {
	std::cout << "BuildingSlot : " << std::endl
		<< "\t Building_id : " << *BuildingSlot_id << std::endl
		<< "\t Points : " << *Points << std::endl
		<< "\t adjacent building slots : " << std::endl;
	for (int i = 0; i < adjacentBuildingSlots->size(); i++) {
		std::cout << "\t\t - " << adjacentBuildingSlots->at(i)->getBuildingSlot_id() << std::endl;
	}
}


/** VGMap IMPLEMENTATION **/

VGMap::VGMap() {
	BuildingSlots = new std::vector<BuildingSlot *>();

}
VGMap::VGMap(std::string n) {
	BuildingSlots = new std::vector<BuildingSlot *>();
	name = new std::string(n);

}
VGMap::VGMap(std::vector<BuildingSlot *> *BuildingSlots_, std::string n) {
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

void VGMap::printVGMap() {
	for (int i = 0; i < BuildingSlots->size(); i++) {
		BuildingSlots->at(i)->print();
	}

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







