/*
 * WorldStats.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#ifndef WORLDSTATS_H_
#define WORLDSTATS_H_

#include "GameStatsDecorator.h"


class WorldStats : public GameStatsDecorator {
private:
	std::vector<Player*> players;
public:
	WorldStats(GameStats *gameStats) : GameStatsDecorator(gameStats) {
		for(Player *player : gameStats->getPlayers()) {
			player->Detach(gameStats);
			player->Attach(this);
		}
		players = gameStats->getPlayers();
	}
	~WorldStats();
	void Update();
	void display();
	std::vector<Player*> getPlayers() {
		return players;
	}
};


#endif /* WORLDSTATS_H_ */
