/*
SaveFile.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef SAVEFILE_H
#define SAVEFILE_H

#include "AbstractSave.h"
#include "SaveAdapter.h"

class SaveFile : public AbstractSave {
protected:
	SaveAdapter *saveAdapter;

public:
	void save(Map map, std::string fileType, std::string fileName) override;
};

#endif