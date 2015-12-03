/*
LoadFile.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef LOADFILE_H
#define LOADFILE_H

#include "AbstractLoad.h"
#include "LoadAdapter.h"

class LoadFile : public AbstractLoad {
protected:
	LoadAdapter *loadAdapter;

public:
	bool load(std::string fileType, std::string fileName) override;
};

#endif