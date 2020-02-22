#include "Resources.h"
#include <random>;
#include <vector>;

#include <iostream>;



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
std::string Tile::typeToString(Tile::Types t) {
	if (t = sheep) 
		return "sheep";
	if (t = wheet)
		return "wheet";
	if (t = timber)
		return "timber";
	if (t = stone)
		return "stone";

}
void  Tile::setNumOfResources() {
	for (int i = 0; i < 4; i++) {
		if (*this->typeArray[i] == Tile::Types::sheep)
			this->numOfResources[0]++;
		if (*this->typeArray[i] == Tile::Types::wheet)
			this->numOfResources[1]++;
		if (*this->typeArray[i] == Tile::Types::stone)
			this->numOfResources[2]++; 
		if (*this->typeArray[i] == Tile::Types::timber)
			this->numOfResources[3]++;
	}
};
int Tile::numOfSheep() {
	return *this->numOfResources[0];
}
int Tile::numOfStone() {
	return *this->numOfResources[1];
}
int Tile::numOfWheet() {
	return *this->numOfResources[2];
}
int Tile::numOfTimper() {
	return *this->numOfResources[3];
}
void Tile::toString(){
	std::cout << "The tile has following resources: " << std::endl;
	std::cout << "upleft: " << this->typeToString(this->getUpLeft()) << std::endl;
	std::cout << "upright: " << this->typeToString(this->getUpRight()) << std::endl;
	std::cout << "downright: " << this->typeToString(this->getDownRight()) << std::endl;
	std::cout << "downleft: " << this->typeToString(this->getDownLeft()) << std::endl;
	std::cout << "Number of resources: " << std::endl;
	std::cout << "Sheep " << this->numOfSheep() << std::endl;
	std::cout << "Wheet " << this->numOfWheet() << std::endl;
	std::cout << "Stone " << this->numOfStone() << std::endl;
	std::cout << "Timper" << this->numOfTimper() << std::endl;
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
Building::Building() {
	cost = new int(0);
	type = nullptr;
	*isFlipped = false;
}
Building::Building(int num,Type t) {
	cost = new int(num);
	*type = t;
	*isFlipped = false;
}
Building::Building(int num,Type t,bool s) {
	cost=new int(num);
	*type = t;
	*isFlipped = s;
}
Building::~Building() {
	delete type;
	delete cost;
	delete isFlipped;
}
void Building::setFlipped(bool s) {
	this->isFlipped = &s;
}
bool Building::getIsFlipped() {
	return this->isFlipped;
}
void Building::turn() {
	if (this->getIsFlipped() == false)
		this->setFlipped(new bool(true));
	else {
		this->setFlipped(new bool(false));
	}
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
Tile::Types Tile::sToTypes(std::string str)
{
	if (str == "sheep")
		return sheep;
	else if (str == "wheet")
		return wheet;
	else if (str == "stone")
		return stone;
	else if (str == "timber")
		return timber;
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
Hand::Hand() {
	numOfStone = new int(0);
	numOfTimber = new int(0);
	numOfSheep = new int(0);
	numOfWheet = new int(0);
}
Hand::Hand(int stone, int timber, int tree, int wheet) {
	numOfStone = new int(stone);
	numOfTimber = new int(timber);
	numOfSheep = new int(tree);
	numOfWheet = new int(wheet);
}
int Hand::getNumOfStone() {
	return *numOfStone;
}
int Hand::getNumOfTimber() {
	return *numOfTimber;

}
int Hand::getNumOfSheep() {
	return *numOfSheep;
}

int Hand::getNumOfWheet() {
	return *numOfWheet;
}

void Hand::setNumOfStone(int i) {
	numOfStone = new int (i);
}
void Hand::setNumOfTimber(int i) {
	numOfTimber = new int(i);
}
void Hand::setNumOfSheep(int i) {
	numOfSheep = new int(i);
}
void Hand::setNumOfWheet(int i) {
	numOfWheet = new int(i);
}
//void Hand::exchange(GBMap gbmap) {//need to see the GameBoard part.........
//	std::cout << "How many players are in the game?";
//	int* numOfPlayers = new int();
//	std::cin >> *numOfPlayers; 
//	if (*numOfPlayers == 2) {
//		std::cout << "You can use the ceter 5*5 area....." << std::endl;
//	}
//	if (*numOfPlayers == 3) {
//		std::cout << "You can use the light center area and the top and bottom green square..." << std::endl;
//	}
//	if (*numOfPlayers == 4) {
//		std::cout << "You can use the entire area...." << std::endl;
//	}
//	else {
//		std::cout << "The game can't be played by more than 4 players, game over. Yes, I am serious, it's over." << std::endl;
//		exit(0);
//	}
//	
//	 bool valid = false;
//	 int* position = new int();
//	 while (!valid) {
//		 std::cout << "Please enter the slot you want to put ur tile :" << std::endl;
//		 
//		 std::cin >> *position;
//		 if (*numOfPlayers == 2) {
//			 if (*position % 10 >= 1 && *position % 10 <= 5 && *position >= 11 && *position <= 55 )
//				 valid = true;
//			 else {
//				 std::cout << "The slot does not exist, try again...." << std::endl;
//				 valid = false;
//				 continue;
//			 }
//		 }
//		 if (*numOfPlayers == 3) {
//			 if (*position % 10 >= 1 && *position % 10 <= 5 && *position > 1 && *position < 66)
//				 valid = true;
//			 else {
//				 std::cout << "The slot does not exist, try again...." << std::endl;
//				 valid = false;
//				 continue;
//			 }
//		 }
//		 if (*numOfPlayers == 4) {
//			 if (*position % 10 >= 0 && *position % 10 <= 6 && *position > 1 && *position < 66 && *position != 6 && *position != 60)
//				 valid = true;
//			 else {
//				 std::cout << "The slot does not exist, try again...." << std::endl;
//				 valid = false;
//				 continue;
//			 }
//		 }
//	 }
//	 GBMapLoader* maploader = new GBMapLoader();
//	 if (*numOfPlayers == 2)
//		 maploader->readfromfile("2PGBMap.txt");
//	 if (*numOfPlayers == 3)
//		 maploader->readfromfile("3PGBMap.txt");
//	 else {
//		 maploader->readfromfile("4PGBMap.txt");
//	 }
//
//	
//	 TileSlot t = gbmap.SearchById(&gbmap, *position);
//	 Tile tile = t.getTile();
//	 tile.setNumOfResources();
//	 /**this->numOfStone = &tile.numOfStone;
//	 *this->numOfTimber = &tile.numOfTimper;
//	 *this->numOfWheet = &tile.numOfWheet;
//	 *this->numOfSheep = &tile.numOfSheep;
//	 */
//
//};
int main(int argc, char* argv[]) {
	Tile *y = new Tile(Tile::sheep, Tile::stone, Tile::stone, Tile::sheep);
	y->toString();
	
	
	
}
