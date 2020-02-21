#include "Resources.h"
#include <random>;

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
Building* BuildingDeck::draw() {
	int n1 = rand() % 4 + 1;
	int n2 = rand() % 5;
	while (allBuilding[n1][n2] == nullptr) {
		int n1 = rand() % 4 + 1;
		int n2 = rand() % 5;
	}
	return allBuilding[n1][n2];
}
Tile::Types Tile::getRandomType() {
	int ranNum = rand() % 4 + 1;
	
	switch (ranNum)
	{
	case 1:
		return Tile::Types::sheep;
		break;
	case 2:
		return Tile::Types::wheet;
		break;
	case 3:
		return Tile::Types::stone;
		break;
	case 4:
		return Tile::Types::timber;
		break;
	}
}
Tile* TileDeck::draw() {
	Tile::Types one;
	Tile::Types two;
	Tile::Types three;
	Tile* tile =new Tile();
	for (int i = 0; i < 60; i++) {
		int numOfDifType = rand() % 3 + 2;//the number of different types of resources is 2 or 3, make it random
		
		if (numOfDifType == 2) {
			int numOfOneSource = rand() % 2+1;
			//decides the type of each space
			if (numOfOneSource == 1) {//there are two types of resources and the number of one of it is 1, that means the other has 3
				one = tile->getRandomType();
				two = tile->getRandomType();
				while (two == one) {
					two = tile->getRandomType();
				}
				tile = new Tile(one, two, two, two);
				return tile;

			}
			else
			{
				one = tile->getRandomType();
				two = tile->getRandomType();
				while (two == one) {
					two = tile->getRandomType();
				}
				int randomCases = rand() % 2 + 1;
				if (randomCases == 1)
					tile = new Tile(one, two, one, two);//here is the case one
				else
					tile = new Tile(one, one, two, two);//case 2
				return tile;
			}
			allTiles[i] = tile;

		}
		else {
			one = tile->getRandomType();
			two = tile->getRandomType();
			while (two == one) {
				two = tile->getRandomType();
			}
			three = tile->getRandomType();
			while (three == one || three == two) {
				three = tile->getRandomType();
			}
			int cases = rand() % 2 + 1;
			if (cases = 1) {
				tile = new Tile(one, one, two, three);
				return tile;
			}
			else {
				tile = new Tile(one, one, three, two);
				return tile;//  because player can choose different ways to place the tile on the gameboard, thoses two cases are all the possible combinations we've got
			}
		}
	}
}
int Hand::getNumOfStone() {
	return numOfStone;
}
int Hand::getNumOfTimber() {
	return numOfTimber;

}
int Hand::getNumOfTree() {
	return numOfTree;
}

int Hand::getNumOfWheet() {
	return numOfWheet;
}
Tile Hand::getTile1() {
	return *this->tile1;
}
Tile Hand::getTile2() {
	return *this->tile2;
}
void Hand::setTile1(Tile t) {
	*this->tile1 = t;
}
void Hand::setTile2(Tile t) {
	*this->tile2 = t;
}
void Hand::setNumOfStone(int i) {
	numOfStone = i;
}
void Hand::setNumOfTimber(int i) {
	numOfTimber = i;
}
void Hand::setNumOfTree(int i) {
	numOfTree = i;
}
void Hand::setNumOfWheet(int i) {
	numOfWheet = i;
}
void exchange() {//need to see the GameBoard part.........

};
int main(int argc, char* argv[]) {
	Tile *y = new Tile(Tile::sheep, Tile::stone, Tile::stone, Tile::sheep);
	TileDeck* x = new TileDeck();
	Tile* z = x->draw();
	
}
