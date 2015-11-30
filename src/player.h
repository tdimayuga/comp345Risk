/*
 * Player.h
 *
 *  Created on: Oct 23, 2015
 *      Author: Sean
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>

#include "Subject.h"

namespace risk {

class Country;

class Player : public Subject {

private:
	std::vector<Country*> countries;
	int armies;
	int continents;
	std::string playerName;
	int battlesWon;

public:
	Player();
	Player(int, std::string);
	~Player();

	std::vector<Country*> getCountries();
	int getArmies();
	int getContinents();
	std::string getName();
	int getBattlesWon();

	void addWin();
	void setCountry(Country*);
	void addArmies(int);
	void removeArmies(int);
	void addContinents(int);

	bool attackCountry(Country country, int armies);
};

} /* namespace GameDriver */

#endif /* PLAYER_H_ */
