#pragma once
#ifndef RESOURCES_H
#define RRESOURCES_H
#include <iostream>

class Tile;
class TileDeck;
class Building;
class BuildingDeck;
class Hand;
class Tile {


public:
	Tile();
	enum Types { sheep, wheet, stone, timber };
	Tile(Types one, Types two, Types three, Types four);
	~Tile();
	Types sToTypes(std::string s);
	Types& getUpLeft();
	Types& getUpRight();
	Types& getDownLeft();
	Types& getDownRight();
	void setUpLeft(Types s);
	void setUpRight(Types s);
	void setDownLeft(Types s);
	void setDownRight(Types s);
	Types getRandomType();
	void setNumOfResources();
	void toString();

private:
	int* numOfResources[4] = { 0,0,0,0 }; //index0:sheep index1:wheet index2:stone index3:timber
	Types* typeArray[4];
	Types* upleft;
	Types* upright;
	Types* downleft;
	Types* downright;

};


class TileDeck {
private: Tile * allTiles[60];
public:
	Tile * draw();
	TileDeck();
	~TileDeck();

};
class Building {
public:
	enum Type { sheep, stone, timber, wheet };
	Building();
	Building(int num, Type t);
	Building(int cost, Type type, bool s);
	~Building();
	Type& getType();
	int& getCost();
	void setType(Type type);
	void setCost(int cost);
	void setFlipped(bool s);
	void turn();
	bool& getIsFlipped();

private:
	bool* isFlipped;
	int* cost;
	Type* type;


};

class BuildingDeck {
	BuildingDeck();
	Building* allBuilding[4][6];
public:
	Building&  draw();

};


class Hand {
private:

	int *numOfSheep;
	int *numOfStone;
	int *numOfWheet;
	int *numOfTimber;

public:
	Hand();
	Hand(int tree, int stone, int wheet, int timber);
	//void exchange(GBMap gbmp);
	int& getNumOfSheep();
	int& getNumOfStone();
	int& getNumOfWheet();
	int& getNumOfTimber();
	void setNumOfSheep(int i);
	void setNumOfTimber(int i);
	void setNumOfStone(int i);
	void setNumOfWheet(int i);

};


#endif // !RESOURCES_H

