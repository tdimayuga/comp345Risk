/*
 * GameStats.h
 *
 *  Created on: Nov 25, 2015
 *      Author: Sean-Frankel Gaon Canlas
 */

#ifndef GAMESTATS_H_
#define GAMESTATS_H_

#include "Observer.h"
#include "player.h"

class GameStats : public Observer {
protected:
	std::vector<Player*> players;
public:
	GameStats();
	~GameStats();
	virtual void addPlayer(Player *player) = 0;
	virtual void Update();
	virtual void display() = 0;
	virtual std::vector<Player*> getPlayers() = 0;
};

#endif /* GAMESTATS_H_ */
