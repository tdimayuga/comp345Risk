#pragma once
/*
AbstractSave.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef ABSTRACTSAVE_H
#define ABSTRACTSAVE_H

#include "map.h"

#include <string>

class AbstractSave {
public:
	virtual void save(Map map, std::string fileType, std::string fileName) = 0;
};

#endif