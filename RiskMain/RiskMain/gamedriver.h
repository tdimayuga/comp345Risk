/*
 * GameDriver.h
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#ifndef GAMEDRIVER_H_
#define GAMEDRIVER_H_

#include "territory.h"
#include "player.h"
#include "map"


class GameDriver {

	std::vector<Player> players;
	int phase;
	int subphase;
	std::vector<Territory> allTerritory;
	bool winner;

public:
	GameDriver();
	~GameDriver();

	std::vector<Player>* getPlayers();
	int getPhase();
	int getSubPhase();
	int getNumberOfPlayers();
	int getStartingArmy(int);
	std::vector<Territory> getTerritory();

	void setPlayers(int);
	void setPhase(int);
	void setSubPhase(int);
	
	void gameSetup();
	void phaseController();
	void subphaseController();

	void deploy();
	void attack();
	void reinforce();
	bool confirm();

};


#endif /* GAMEDRIVER_H_ */
