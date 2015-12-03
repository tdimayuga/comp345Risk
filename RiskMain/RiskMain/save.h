/*
save.h
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef SAVE_H
#define SAVE_H

#include "map.h"

#include <string>

class Save
{
private:
	Map map;
	std::string filePath;

public:
	Save(Map, std::string);
	~Save();
};

#endif