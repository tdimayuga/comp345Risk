/*
SaveAdapter.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef SAVEADAPTER_H
#define SAVEADAPTER_H

#include "AbstractSave.h"
#include "AdvanceSave.h"

class SaveAdapter : public AbstractSave {
protected:
	AdvanceSave *advanceSaver;
	//std::string type;

public:
	SaveAdapter(std::string fileType);
	void save(Map map, std::string fileType ,std::string fileName) override;
};

#endif