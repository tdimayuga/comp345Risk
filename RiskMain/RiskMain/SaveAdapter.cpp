/*
SaveAdapter.cpp
SaveLoad for Risk

Created by Dich-Ky Tran on 21/11/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#include <string>
//#include <utility>
//#include <algorithm>
//#include <functional>
//#include <cctype>

#include "SaveAdapter.h"
#include "SaveText.h"

using namespace std;

SaveAdapter::SaveAdapter(string fileType)
{
	/*transform(fileType.begin(), fileType.end(), fileType.begin(), tolower);

	this->type = fileType;*/

	if (fileType == "txt")
		this->advanceSaver = new SaveText();
}

void SaveAdapter::save(Map map, string fileType,string fileName)
{
	if (fileType == "txt")
		this->advanceSaver->saveText(map, fileName);
}