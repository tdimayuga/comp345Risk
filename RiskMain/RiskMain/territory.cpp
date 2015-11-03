/*
territory.cpp
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#include "territory.h"

using namespace std;

Territory::Territory()
{
	name = "";
	x = NULL;
	y = NULL;
}

void Territory::setName(string nameX)
{
	name = nameX;
}

void Territory::setXcoordinate(int val)
{
	x = val;
}

void Territory::setYcoordinate(int val)
{
	y = val;
}

void Territory::setContinent(string cont)
{
	continent = cont;
}

void Territory::addAdjTerritory(string terr)
{
	adjacentTerritory.push_back(terr);
}

void Territory::clearTerritories()
{
	adjacentTerritory.clear();
}

//Game Driver

string Territory::getOwner() {
	return owner;
}

int Territory::getArmies() {
	return army;
}

void Territory::setOwner(string ownerx) {
	owner = ownerx;
}

void Territory::setArmies(int armiesx) {
	army = armiesx;
}