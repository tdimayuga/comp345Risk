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

namespace risk {

class Country;

class Player {

private:
	std::vector<Country*> countries;
	int armies;
	int continents;
	std::string playerName;

public:
	Player();
	Player(Country*, int, std::string);
	~Player();

	std::vector<Country*> getCountries();
	int getArmies();
	int getContinents();

	void setCountry(Country*);
	void addArmies(int);
	void removeArmies(int);
	void addContinents(int);

	bool attackCountry(Country country, int armies);
};

} /* namespace GameDriver */

#endif /* PLAYER_H_ */
