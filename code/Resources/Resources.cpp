//
// Created by Kunming Yang on 2020-01-22.
//

#include "Resources.h"
Tile::Tile(Types one,Types two,Types three,Types four) {
	this->upleft = &one;
	this->upright = &two;
	this->downright = &three;
	this->downleft = &four;

}
Tile::~Tile() {
	delete upleft;
	delete upright;
	delete downleft;
	delete downright;
}
Tile::Types Tile::getDownLeft() {
	return *downleft;
}
Tile::Types Tile::getDownRight() {
	return *downright;
}
Tile::Types Tile::getUpLeft() {
	return *upleft;
}
Tile::Types Tile::getUpRight() {
	return *upright;
}
void Tile::setDownLeft(Types s) {
	*downleft = s;
}
void Tile::setDownRight(Types s) {
	*downright = s;
}
void Tile::setUpLeft(Types s) {
	*upleft = s;
}
void Tile::setUpRight(Types s) {
	*upright = s;
}
Building::Type Building::getType()  {
	return *type;
}
int Building::getCost() {
	return *cost;
}
void Building::setCost(int n) {
	cost = new int(n);
}
void Building::setType(Type s)
{
	*type = s;
}
Building::Building(int num,Type t) {
	cost=new int(num);
	*type = t;
}
Building::~Building() {
	delete type;
	delete cost;
}
BuildingDeck::BuildingDeck() {
	for (int i = 0; i < 6; i++) {
		allBuilding[0][i] = new Building(int(i + 1), Building::Type::sheep);
	}
	for (int i = 0; i < 6; i++) {
		allBuilding[1][i] = new Building(int(i + 1), Building::Type::stone);
	}
	for (int i = 0; i < 6; i++) {
		allBuilding[2][i] = new Building(int(i + 1), Building::Type::timber);
	}
	for (int i = 0; i < 6; i++) {
		allBuilding[3][i] = new Building(int(i + 1), Building::Type::wheet);
	}
}
*Building BuildingDeck::draw() {
	int n1 = rand() % 4 + 1;
	int n2 = rand() % 5;
	while (allBuilding[n1][n2] == nullptr) {
		int n1 = rand() % 4 + 1;
		int n2 = rand() % 5;
	}
	return allBuilding[n1][n2];
}
