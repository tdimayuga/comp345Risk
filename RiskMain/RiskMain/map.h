/*
map.h
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef MAP_H
#define MAP_H

#include "continent.h"
#include "territory.h"

#include <string>
#include <vector>

class Map
{
private:
	std::string author;
	std::string image;
	std::string wrap;
	std::string scroll;
	std::string warn;

public:
	std::vector<Continent> continents;
	std::vector<Territory> territories;

	Map();
	//~Map();

	std::string getAuthor(){return author;};
	std::string getImage(){return image;};
	std::string getWrap(){return wrap;};
	std::string getScroll(){return scroll;};
	std::string getWarn(){return warn;};

	void setAuthor(std::string);
	void setImage(std::string);
	void setWrap(std::string);
	void setScroll(std::string);
	void setWarn(std::string);
	void addContinents(Continent);
	void addTerritories(Territory);

};

#endif