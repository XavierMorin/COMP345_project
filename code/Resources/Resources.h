//
// Created by Kunming Yang on 2020-01-22.
//
#pragma once

#ifndef PROJECT_RESOURCES_H
#define PROJECT_RESOURCES_H

#include <string>

class Tile;
	class TileDeck;
	class Building;
	class BuildingDeck;

	class Tile {
	public:
        enum Types { sheep, wheet, stone, timber };
        Types* upleft;
        Types* upright;
        Types* downleft;
        Types* downright;

		Tile();
		Tile(Types one, Types two, Types three, Types four);
		~Tile();//destructor
		Types getUpLeft();
		Types getUpRight();
		Types getDownLeft();
		Types getDownRight();
		void setUpLeft(Types s);
		void setUpRight(Types s);
		void setDownLeft(Types s);
		void setDownRight(Types s);
		static Types sToTypes(std::string);


    };

	class TileDeck {

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

class BuildingDeck{
private:

	Building* allBuilding[4][6];

public:
    BuildingDeck();
    Building draw();

};
class Hand{
private:
	
public:
	void exchange();
};


#endif //PROJECT_RESOURCES_H
