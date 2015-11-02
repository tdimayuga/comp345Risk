/*
 * map.h
 *
 *  Created on: Oct 28, 2015
 *      Author: Trisha Dimayuga
 *  Student ID: 26922287
 */

#ifndef MAP_H_
#define MAP_H_
#include "territory.h"
#include "continent.h"


#include <string>
#include <array>

using namespace std;

class Map{

private:
	Territory *t;
	/*Territory t1;
	Territory t2;
	Territory t3;
	Territory t4;
	Territory t5;
	Territory t6;
	Territory t7;
	Territory t8;
	Territory t9;
	Territory t10;
	Territory t11;
	Territory t12;
	Territory t13;
	Territory t14;
	Territory t15;
	Territory t16;*/

public:
	Map(Territory[]);

	string toString();
};



#endif /* MAP_H_ */
