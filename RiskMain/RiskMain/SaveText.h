/*
SaveText.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef SAVETEXT_H
#define SAVETEXT_H

#include "AdvanceSave.h"

class SaveText : public AdvanceSave {
public:
	void saveText(Map map, std::string fileName) override;
};

#endif