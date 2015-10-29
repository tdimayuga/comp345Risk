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
	int subphase;
	Country allCountries[1];

public:
	GameDriver();
	~GameDriver();

	std::vector<Player*> getPlayers();
	int getPhase();
	int getSubPhase();
	Country* getCountries();

	void setPlayers(Player*);
	void setPhase(int);
	void setSubPhase(int);
	void setCountries();

	void gameSetup();
	void phaseController();

	void deploy();
	void attack();
	void reinforce();
	bool confirm();

};

} /* namespace GameDriver */

#endif /* GAMEDRIVER_H_ */
