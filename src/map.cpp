/*
 * map.cpp
 *
 *  Created on: Oct 28, 2015
 *      Author: Trisha Dimayuga
 *  Student ID: 26922287
 */

#include "map.h"
#include "territory.h"


#include <iostream>
#include <array>

Map::Map(Territory territory[]){
/*
	t[0] = Territory("A", 1, 1, "NORTH");
	t[1] = Territory("B", 1, 2, "NORTH");
	t[2] = Territory("C", 1, 3, "NORTH");
	t[3] = Territory("D", 1, 4, "NORTH");
	t[4] = Territory("E", 2, 1, "WEST");
	t[5] = Territory("F", 2, 2, "WEST");
	t[6] = Territory("G", 2, 3, "EAST");
	t[7] = Territory("H", 2, 4, "EAST");
	t[8] = Territory("I", 3, 1, "WEST");
	t[9] = Territory("J", 3, 2, "WEST");
	t[10] = Territory("K", 3, 3, "EAST");
	t[11] = Territory("L", 3, 4, "EAST");
	t[12] = Territory("M", 4, 1, "SOUTH");
	t[13] = Territory("N", 4, 2, "SOUTH");
	t[14] = Territory("O", 4, 3, "SOUTH");
	t[15] = Territory("P", 4, 4, "SOUTH");
	*/

	t = territory;

}



string Map::toString(){
	string str= "\n =============================\n";
	int count = 0;
	t[1].getName();
	for(int i = 0; i < 4 ; i++){
		str += " | ";
		for(int j = 0 ; j < 4 ; j++){

		if(t[count].getOwner() == "")
			str +=  t[count].getName() + "[-]" + " | ";
		else
			str +=  t[count].getName() + "[" + t[count].getOwner() + "] | ";

		count++;
		}
		str += "\n =============================\n";
	}

	return str;

}


