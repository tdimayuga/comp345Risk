/*
 * GameDriver.h
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#ifndef GAMEDRIVER_H_
#define GAMEDRIVER_H_

#include "country.h"
#include "player.h"

namespace risk {

class GameDriver {

	std::vector<Player*> players;
	int phase;
	Country allCountries[1];
	bool winner;

public:
	GameDriver();
	~GameDriver();

	std::vector<Player*> getPlayers();
	int getPhase();
	Country* getCountries();
	int getAmtPlayers();

	void addPlayers(Player*);
	void setPhase(int);
	void setCountries();

	void gameSetup();
	void phaseController();
	void subphaseController();

	void deploy(Player*);
	void attack(Player*);
	void reinforce(Player*);
	bool confirm();

};

} /* namespace GameDriver */

#endif /* GAMEDRIVER_H_ */
