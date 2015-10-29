/*
 * Country.h
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#ifndef COUNTRY_H_
#define COUNTRY_H_

namespace risk {

class Player;

class Country {

	Player* owner;
	int armies;

public:
	Country();
	~Country();

//	Country* getAttackable();
	Player* getOwner();
	int getArmies();

//	void setAttackable(Country*);
	void setOwner(Player*);
	void setArmies(int);

};

} /* namespace GameDriver */

#endif /* COUNTRY_H_ */
