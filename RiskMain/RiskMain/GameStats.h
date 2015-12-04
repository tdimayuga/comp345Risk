/*
 * GameStats.h
 *
 *  Created on: Nov 25, 2015
 *      Author: Sean
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
	GameStats(Player *player);
	~GameStats();
	void addPlayer(Player *player);
	void Update();
	virtual void display() = 0;
	virtual std::vector<Player*> getPlayers() {
		return players;
	}
};


#endif /* GAMESTATS_H_ */
