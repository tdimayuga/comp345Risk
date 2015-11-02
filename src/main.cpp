/*

 * main.cpp
 *
 *  Created on: Oct 28, 2015
 *      Author: Trisha Dimayuga
 *  Student ID: 26922287
 */

#include "map.h"
#include "territory.h"

#include <array>
#include <iostream>
int main(){

Territory t[16];
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

	Map m(t);

	// empty map
	cout << "Empty map..." << m.toString() << endl;

	//setting owner for B and C territory.
	t[1].setOwner("1");
	t[2].setOwner("1");

	cout << "Set owner of territory B and C to player 1." << endl;

	// setting 5 armies for territory B
	t[1].setArmies(5);
	cout << "Set number of armies in territory B to 5." << endl;


	// Printing new map
	cout << "\nNew map showing territory owner..." << m.toString() << endl;

	// Displays armies for all of Player 1's territories
	cout << "Displaying Player 1 armies..." << endl;
	for(int i=0; i < 16 ; i++){
		if(t[i].getOwner() == "1")
			cout << t[i].getName() << " has " << t[i].getArmies() << " armies." << endl;
	}


	//Checking for naighbours
	cout << "\nChecking for neighbours..." << endl;
	cout << "Is A a neighbour of B? " << t[0].isNeighbour(t[1]) << endl;
	cout << "Is A a neighbour of D? " << t[0].isNeighbour(t[3]) << endl;
	cout << "Is A a neighbour of L? " << t[0].isNeighbour(t[11]) << endl;

	/*
	cout << "Is A a neighbour of E? " << t[0].isNeighbour(t[4]) << endl;
	cout << "Is H a neighbour of E? " << t[7].isNeighbour(t[4]) << endl;
	cout << "Is A a neighbour of M? " << t[0].isNeighbour(t[12]) << endl;
	cout << "Is A a neighbour of P? " << t[0].isNeighbour(t[15]) << endl;
	*/

	return 0;


}

