/*
 * territory.h
 *
 *  Created on: Oct 28, 2015
 *      Author: Trisha Dimayuga
 *  Student ID: 26922287
 */

#ifndef TERRITORY_H_
#define TERRITORY_H_

#include <string>
using namespace std;

class Territory{

private:
	string name;
	int x;
	int y;
	string continent;
	string owner;
	int army;


public:
	Territory();
	Territory(string, int, int, string);

	void setName(string);
	void setXCoordinate(int);
	void setYCoordinate(int);
	void setCoordinate(int, int);
	void setContinent(string);
	void setOwner(string);
	void setArmies(int);

	string getName() {return name;};
	int getXCoordinate() {return x;};
	int getYCoordinate() {return y;};
	string getContinent() {return continent;};
	string getOwner() {return owner;};
	int getArmies() {return army;};

	string isNeighbour(Territory);
	bool isAttackable(Territory, string);



};



#endif /* TERRITORY_H_ */
