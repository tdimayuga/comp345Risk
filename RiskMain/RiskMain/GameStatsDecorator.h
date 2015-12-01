/*
 * GameStatsDecorator.h
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#ifndef GAMESTATSDECORATOR_H_
#define GAMESTATSDECORATOR_H_

#include "GameStats.h"

class GameStatsDecorator : public GameStats {
protected:
	GameStats *gameStats;
public:
	GameStatsDecorator(GameStats *gameStats) {
		this->gameStats = gameStats;
	};
	~GameStatsDecorator();
	void Update();
	void display();

};

#endif /* GAMESTATSDECORATOR_H_ */
