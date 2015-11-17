/*
map.cpp
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#include "map.h"

using namespace std;

Map::Map()
{
	author = "";
	image = "";
	wrap = "";
	scroll = "";
	warn = "";
}

void Map::setAuthor(string authorX)
{
	author = authorX;
}

void Map::setImage(string imageX)
{
	image = imageX;
}

void Map::setWrap(string wrapX)
{
	wrap = wrapX;
}

void Map::setScroll(string scrollX)
{
	scroll = scrollX;
}

void Map::setWarn(string warnX)
{
	warn = warnX;
}

void Map::addContinents(Continent cont)
{
	continents.push_back(cont);
}

void Map::addTerritories(Territory terr)
{
	territories.push_back(terr);
}

//bool Map::isValidTerritory(string name)
//{
//	/*if (find(this->territories.begin(), this->territories.end(), name) != this->territories.end())
//		return true;
//
//	return false;*/
//}