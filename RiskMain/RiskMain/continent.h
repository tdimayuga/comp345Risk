/*
continent.h
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#ifndef CONTINENT_H
#define CONTINENT_H

#include <string>

class Continent
{
private:
	std::string name;
	int val;
public:
	Continent();
	Continent(std::string,int);
	//~Continent();

	std::string getName(){return name;};
	int getVal(){return val;};
	
	void setName(std::string);
	void setVal(int);
};

#endif