/*
AbstractLoad.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef ABSTRACTLOAD_H
#define ABSTRACTLOAD_H

#include "map.h"

#include <string>

class AbstractLoad {
protected:
	Map map;

public:
	virtual bool load(std::string fileType, std::string fileName) = 0;
	Map getMap() { return map; };
};

#endif