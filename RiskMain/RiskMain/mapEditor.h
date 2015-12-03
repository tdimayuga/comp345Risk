/*
mapEditor.h
Map Editor for Risk

Created by Dich-Ky Tran on 08/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include "map.h"
#include "territory.h"
#include "continent.h"

#include <string>

class MapEditor
{
private:
	Map map;
public:
	MapEditor();
	~MapEditor();

	void editMap(std::string, std::string);
	void createMap();

	void createContinent();
	void createTerritory();
	void assignTerrToCont(std::string);
	void assignAdjTerr(Territory&);

	bool continentExist(std::string);
	bool territoryExist(std::string);

	bool fileExist (std::string);
};

#endif