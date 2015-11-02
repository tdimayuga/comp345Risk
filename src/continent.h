/*
 * continent.h
 *
 *  Created on: Oct 28, 2015
 *      Author: Trisha Dimayuga
 *  Student ID: 26922287
 */

#ifndef CONTINENT_H_
#define CONTINENT_H_

#include "territory.h"
#include <string>

using namespace std;

class Continent{

private:
	string name;


public:
	Continent();
	void setName(string);

	string getName() {return name;};

};



#endif /* CONTINENT_H_ */
