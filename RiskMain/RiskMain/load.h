/*
load.h
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef LOAD_H
#define LOAD_H

#include "map.h"

#include <string>

class Load
{
private:
	Map map;

public:
	Load(std::string);
	Load();
	//~Load();

	Map getMap(){return map;};
};

#endif