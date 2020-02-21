#pragma once
#ifndef RESOURCES_H
#define RRESOURCES_H

	class Tile;
	class TileDeck;
	class Building;
	class BuildingDeck;
	class Tile {
		
	
	public:
		Tile();
		enum Types { sheep, wheet, stone, timber };
		Tile(Types one, Types two, Types three, Types four);
		~Tile();//
		Types sToTypes(std::string s);
		Types getUpLeft();
		Types getUpRight();
		Types getDownLeft();
		Types getDownRight();
		void setUpLeft(Types s);
		void setUpRight(Types s);
		void setDownLeft(Types s);
		void setDownRight(Types s);
		Types getRandomType();
		void setNumOfResources();
		Types* typeArray[4] = {upleft, upright,downright,downleft};
		int numOfSheep();
		int numOfWheet();
		int numOfStone();
		int numOfTimper();
	private:
		int* numOfResources[4] = {0,0,0,0}; //index0:sheep index1:wheet index2:stone index3:timber
		Types* upleft;
		Types* upright;
		Types* downleft;
		Types* downright;
		

	};
	class TileDeck {
	private: Tile* allTiles[60];
	public:
		Tile* draw();
		TileDeck();
		~TileDeck();
		
	};
class Building{
public:
    enum Type {sheep, stone, timber, wheet};
	Building();
    Building(int cost, Type type);
    ~Building();
	Type getType();
	int getCost();
	void setType(Type type);
	void setCost(int cost);
	
private:

    int* cost;
    Type* type;


};

class BuildingDeck {
	Building* allBuilding[4][6];
public:
	Building* draw();

};
class Hand{
private:
	Tile* tile1;
	Tile* tile2;
	Building* buildings[60];
	int numOfTree;
	int numOfStone;
	int numOfWheet;
	int numOfTimber;

public:
	void exchange();
	Tile getTile1();
	Tile getTile2();
	int getNumOfTree();
	int getNumOfStone();
	int getNumOfWheet();
	int getNumOfTimber();
	void setTile1(Tile t);
	void setTile2(Tile t);
	void setNumOfTree(int i);
	void setNumOfTimber(int i);
	void setNumOfStone(int i);
	void setNumOfWheet(int i);

};


#endif // !RESOURCES_H
