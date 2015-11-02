/*
 * territory.cpp
 *
 *  Created on: Oct 28, 2015
 *      Author: Trisha Dimayuga
 *  Student ID: 26922287
 */

#include "territory.h"

using namespace std;

Territory::Territory(){
	name = "";
	x = 0;
	y = 0;
	continent = "";
	owner = "";
	army = 0;
}

Territory::Territory(string name, int x, int y, string continent){
	this->name =  name;
	this->x = x;
	this->y = y;
	this->continent = continent;
	owner = "";
	army = 0;
}

void Territory::setName(string name){
	this->name = name;
}

void Territory::setXCoordinate(int x){
	this->x = x;
}

void Territory::setYCoordinate(int y){
	this->y = y;
}

void Territory::setCoordinate(int x, int y){
	setXCoordinate(x);
	setYCoordinate(y);
}

void Territory::setContinent(string continent){
	this->continent = continent;
}

void Territory::setOwner(string owner){
	this->owner = owner;
}

void Territory::setArmies(int number){
	this->army = number;
}

string Territory::isNeighbour(Territory b){
	int posX, negX, posY, negY;

	/*if(x + 1 == 5)
		posX = 1;
	else
		posX = x + 1;

	if(x - 1 == 0)
		negX = 4;
	else
		negX = x - 1;*/

	posX = x + 1;
	negX = x - 1;

	if(y + 1 == 5)
		posY = 1;
	else
		posY = y + 1;

	if(y - 1 == 0)
		negY = 4;
	else
		negY = y - 1;

	if(x == b.getXCoordinate() && posY == b.getYCoordinate())
		return "True";
	else if(posX == b.getXCoordinate() && y == b.getYCoordinate())
		return "True";
	else if(posX == b.getXCoordinate() && posY == b.getYCoordinate())
		return "True";
	else if(x == b.getXCoordinate() && negY == b.getYCoordinate())
		return "True";
	else if(negX == b.getXCoordinate() && y == b.getYCoordinate())
		return "True";
	else if(negX == b.getXCoordinate() && negY == b.getYCoordinate())
		return "True";

	return "False";
}


