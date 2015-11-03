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


class GameDriver {

	std::vector<Player*> players;
	int phase;
	int subphase;
	std::vector<Territory> allTerritory;

public:
	GameDriver();
	~GameDriver();

	std::vector<Player*> getPlayers();
	int getPhase();
	int getSubPhase();
	std::vector<Territory> getTerritory();

	void setPlayers(Player*);
	void setPhase(int);
	void setSubPhase(int);
	
	void gameSetup();
	void phaseController();

	void deploy();
	void attack();
	void reinforce();
	bool confirm();

};


#endif /* GAMEDRIVER_H_ */
