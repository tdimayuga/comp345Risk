/*
AdvanceLoad.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef ADVANCELOAD_H
#define ADVANCELOAD_H

#include "map.h"

#include <string>

class AdvanceLoad{
protected:
	Map map;

public:
	virtual bool loadText(std::string fileName) = 0;
};

#endif