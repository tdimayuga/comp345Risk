/*
 * PlayerStats.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#ifndef PLAYERSTATS_H_
#define PLAYERSTATS_H_

#include "GameStats.h"


class PlayerStats : public GameStats {
public:
	PlayerStats() {}
	PlayerStats(Player *player);
	PlayerStats(GameStats *gameStats);
	~PlayerStats();
	void Update();
	void display();
};

#endif /* PLAYERSTATS_H_ */
