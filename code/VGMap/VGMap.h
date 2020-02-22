#pragma once

#ifndef VGMAP_H
#define VGMAP_H

#include <string>
#include <vector>
#include <algorithm>
#include "Resources.h"
class Building;
class BuildingSlot;
class VGMap;

class BuildingSlot {

public:
	//constructors && Destructor
	BuildingSlot(); //Default
	BuildingSlot(int Points_, int BuildingSlot_id_); //parameterized constructor with adjacent BuildingSlots
	BuildingSlot(std::vector<BuildingSlot *> adjacentBuildings_, int Points_, int BuildingSlot_id_); //parameterized constructor with adjacent BuildingSlots
	~BuildingSlot(); // Destructor


					 // Accessors 
	int& getPoints();    // Points accessor
	Building& getBuilding();  // Building accessor 

						 // Mutators
	void setPoints(int size);  // Points mutator
							   //void setBuilding(Building * Building_);  //Building mutator

	void setBuilding(Building b);

							   // adjacent BuildingSlot accessor method
	std::vector<BuildingSlot *>& getAdjacentBuildingSlots();
	// adjacent BuildingSlot mutator method
	void setAdjacentbuildingSlots(std::vector<BuildingSlot *> adjBuildingSlot);
	// add BuildingSlot to adjacent BuildingSlot vector method
	void addAdjacentBuildingSlots(BuildingSlot *BuildingSlot);
	// check if BuildingSlot is adjacent
	bool isAdjacent(BuildingSlot *BuildingSlot);
	int& getBuildingSlot_id();

	void print();



private:


	// vector of all adjacent BuildingSlot
	std::vector<BuildingSlot *> *adjacentBuildingSlots;

	// Number of point for this Slot 
	int *Points;
	int *BuildingSlot_id;

	Building *BuildingBuilt; // to be changed to object Building

};


class VGMap {


public:
	// Constructors && Destructor
	VGMap();
	VGMap(std::string name);// paramaterized constructor
	VGMap(std::vector<BuildingSlot *> *BuildingSlot_, std::string name);// paramaterized constructor
	~VGMap(); // destructor

			  // Accessor method
	std::vector<BuildingSlot *>& getBuildingSlots();

	// Mutator method
	void  setBuildingSlots(std::vector<BuildingSlot *> BuildingSlot_);

	// add BuildingSlot method
	void addBuildingSlot(BuildingSlot *BuildingSlot);

	// PrintVGMap
	void printVGMap();
	// check if a map is a connected graph
	bool isConnectedGraph();
	// check if map contains duplicates
	bool containsDuplicates();
	// remove duplicates from map
	void removeDuplicates();

	void resetVGMap();

private:
	// vector containing pointers to all circular spaces of the VGMap
	std::vector<BuildingSlot *> *BuildingSlots;
	std::string *name;

};
#endif 

