/*
territory.h
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef TERRITORY_H
#define TERRITORY_H

#include "continent.h"

#include <string>
#include <vector>

class Territory
{
private:
	std::string name;
	int x;
	int y;
	std::string continent;
	std::vector<std::string> adjacentTerritory;
	std::string owner;
	

public:
	int army;
	Territory();
	//~Territory();
	
	std::string getName(){return name;};
	int getXcoordinate(){return x;};
	int getYcoordinate(){return y;};
	std::string getContinent(){return continent;};
	std::vector<std::string> getAdjTerritory(){return adjacentTerritory;};

	void setName(std::string);
	void setXcoordinate(int);
	void setYcoordinate(int);
	void setContinent(std::string);
	void addAdjTerritory(std::string);
	void clearTerritories();

	bool isAdjacent(std::string);

	//Game Driver
	std::string getOwner();
	int getArmies();

	void setOwner(std::string);
	void setArmies(int);
};

#endif