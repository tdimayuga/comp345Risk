/*
LoadAdapter.cpp
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#include <string>
//#include <utility>
//#include <algorithm>
//#include <functional>
//#include <cctype>

#include "LoadAdapter.h"
#include "LoadText.h"

using namespace std;

LoadAdapter::LoadAdapter(string fileType)
{
	/*transform(fileType.begin(), fileType.end(), fileType.begin(), tolower);

	this->type = fileType;*/

	if (fileType == "txt")
		this->advanceLoader = new LoadText();
}

bool LoadAdapter::load(string fileType, string fileName)
{
	if (fileType == "txt")
		return this->advanceLoader->loadText(fileName);
	
	return false;
}