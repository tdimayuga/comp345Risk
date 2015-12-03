/*
LoadText.h
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef LOADTEXT_H
#define LOADTEXT_H

#include "AdvanceLoad.h"

class LoadText : public AdvanceLoad {
public:
	bool loadText(std::string fileName) override;
};

#endif