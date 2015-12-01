/*
 * BattleStats.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#ifndef BATTLESTATS_H_
#define BATTLESTATS_H_

#include "GameStatsDecorator.h"

class BattleStats : public GameStatsDecorator {
private:
	std::vector<Player*> players;
public:
	BattleStats(GameStats *gameStats) : GameStatsDecorator(gameStats) {
		for(Player *player : gameStats->getPlayers()) {
			player->Detach(gameStats);
			player->Attach(this);
		}
		players = gameStats->getPlayers();
	}
	~BattleStats();
	void Update();
	void display();
	std::vector<Player*> getPlayers() {
		return players;
	}
};

#endif /* BATTLESTATS_H_ */
