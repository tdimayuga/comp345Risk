/*
AdvanceSave.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef ADVANCESAVE_H
#define ADVANCESAVE_H

#include "map.h"

#include <string>

class AdvanceSave {
public:
	virtual void saveText(Map map, std::string fileName) = 0;
};

#endif