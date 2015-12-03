/*
LoadAdapter.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef LOADADAPTER_H
#define LOADADAPTER_H

#include "AbstractLoad.h"
#include "AdvanceLoad.h"

class LoadAdapter : public AbstractLoad {
protected:
	AdvanceLoad *advanceLoader;
	//std::string type;

public:
	LoadAdapter(std::string fileType);
	bool load(std::string fileType, std::string fileName) override;
};

#endif