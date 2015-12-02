/*
continent.cpp
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#include "continent.h"

using namespace std;

Continent::Continent()
{
	name = "";
	val = NULL;
}

Continent::Continent(string nameX, int valX)
{
	name = nameX;
	val = valX;
}

void Continent::setName(string nameX)
{
	name = nameX;
}

void Continent::setVal(int valX)
{
	val = valX;
}