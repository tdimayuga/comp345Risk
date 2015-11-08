/*
 * Country.h
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <string>

namespace risk {

class Player;

class Country {

	Player* owner;
	int armies;
	std::string name;

public:
	Country();
	Country(Player*, int, std::string);
	~Country();

//	Country* getAttackable();
	Player* getOwner();
	int getArmies();
	std::string getName();

//	void setAttackable(Country*);
	void setOwner(Player*);
	void setArmies(int);
	void setName(std::string);

};

} /* namespace GameDriver */

#endif /* COUNTRY_H_ */
