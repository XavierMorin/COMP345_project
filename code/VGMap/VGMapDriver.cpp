
#include "VGMap.h"
#include <iostream>


int main(int argc, char *argv[]) {
	
	
	BuildingSlot *BuildingSlot11 = new BuildingSlot(1,11);
	BuildingSlot *BuildingSlot12 = new BuildingSlot(1,12);
	BuildingSlot *BuildingSlot13 = new BuildingSlot(1,13);

	BuildingSlot *BuildingSlot21 = new BuildingSlot(2,21);
	BuildingSlot *BuildingSlot22 = new BuildingSlot(2,22);
	BuildingSlot *BuildingSlot23 = new BuildingSlot(2,23);

	BuildingSlot *BuildingSlot31 = new BuildingSlot(3,31);
	BuildingSlot *BuildingSlot32 = new BuildingSlot(3,32);
	BuildingSlot *BuildingSlot33 = new BuildingSlot(3,33);

	BuildingSlot11->addAdjacentBuildingSlot(BuildingSlot12);
	BuildingSlot11->addAdjacentBuildingSlot(BuildingSlot21);

	BuildingSlot12->addAdjacentBuildingSlot(BuildingSlot11);
	BuildingSlot12->addAdjacentBuildingSlot(BuildingSlot13);
	BuildingSlot12->addAdjacentBuildingSlot(BuildingSlot22);

	BuildingSlot13->addAdjacentBuildingSlot(BuildingSlot12);
	BuildingSlot13->addAdjacentBuildingSlot(BuildingSlot23);
	

	BuildingSlot21->addAdjacentBuildingSlot(BuildingSlot11);
	BuildingSlot21->addAdjacentBuildingSlot(BuildingSlot22);
	BuildingSlot21->addAdjacentBuildingSlot(BuildingSlot31);

	BuildingSlot22->addAdjacentBuildingSlot(BuildingSlot12);
	BuildingSlot22->addAdjacentBuildingSlot(BuildingSlot32);
	BuildingSlot22->addAdjacentBuildingSlot(BuildingSlot21);
	BuildingSlot22->addAdjacentBuildingSlot(BuildingSlot23);

	BuildingSlot23->addAdjacentBuildingSlot(BuildingSlot13);
	BuildingSlot23->addAdjacentBuildingSlot(BuildingSlot33);
	BuildingSlot23->addAdjacentBuildingSlot(BuildingSlot22);

	BuildingSlot31->addAdjacentBuildingSlot(BuildingSlot21);
	BuildingSlot31->addAdjacentBuildingSlot(BuildingSlot32);
	

	BuildingSlot32->addAdjacentBuildingSlot(BuildingSlot31);
	BuildingSlot32->addAdjacentBuildingSlot(BuildingSlot22);
	BuildingSlot32->addAdjacentBuildingSlot(BuildingSlot33);


	BuildingSlot33->addAdjacentBuildingSlot(BuildingSlot23);
	BuildingSlot33->addAdjacentBuildingSlot(BuildingSlot32);
	

	//// test adjacency of territories
	//std::cout << "right BuildingSlot 1 is adjacent to right BuildingSlot 2 : " << convertIntToStrBool(rightBuildingSlot1->isAdjacent(rightBuildingSlot2)) << std::endl;
	//std::cout << "right BuildingSlot 2 is adjacent to right BuildingSlot 1 : " << convertIntToStrBool(rightBuildingSlot2->isAdjacent(rightBuildingSlot1)) << std::endl;
	//std::cout << "right BuildingSlot 3 is adjacent to right BuildingSlot 2 : " << convertIntToStrBool(rightBuildingSlot3->isAdjacent(rightBuildingSlot2)) << std::endl << std::endl;



	VGMap *map = new VGMap("Guilford");

	

	// add territories to map
	map->addBuildingSlot(BuildingSlot11);
	map->addBuildingSlot(BuildingSlot12);
	map->addBuildingSlot(BuildingSlot13);
	map->addBuildingSlot(BuildingSlot21);
	map->addBuildingSlot(BuildingSlot22);
	map->addBuildingSlot(BuildingSlot23);
	map->addBuildingSlot(BuildingSlot31);
	map->addBuildingSlot(BuildingSlot32);
	map->addBuildingSlot(BuildingSlot33);
	

	//BuildingSlot4->print();
	//BuildingSlot5->print();

	/*std::cout << "DUPLICATES : " << convertIntToStrBool(map->containsDuplicates()) << std::endl;
	map->removeDuplicates();
	std::cout << "DUPLICATES : " << convertIntToStrBool(map->containsDuplicates()) << std::endl;*/




	std::cout << std::endl << "##################### MAP TERRITORIES #####################" << std::endl;
	for (int j = 0; j < map->getBuildingSlots().size(); j++) {
		
		std::cout << "Points : " << map->getBuildingSlots().at(j)->getPoints() << std::endl;
		

		for (int l = 0; l < map->getBuildingSlots().at(j)->getAdjacentBuildingSlots().size(); l++) {
			std::cout << "\t Points of BuildingSlot : " << map->getBuildingSlots().at(j)->getAdjacentBuildingSlots().at(l)->getPoints() << std::endl;
		}
	}
	
	std::cout << "\n \tIs connected Graph: " << map->isConnectedGraph()<<"\n";
	system("pause");

	delete BuildingSlot11;
	delete BuildingSlot12;
	delete BuildingSlot13;
	delete BuildingSlot21;
	delete BuildingSlot22;
	delete BuildingSlot23;
	delete BuildingSlot31;
	delete BuildingSlot32;
	delete BuildingSlot33;
	delete map;

	return 0;
}
