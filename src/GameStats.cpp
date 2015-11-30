/*
 * GameStats.cpp
 *
 *  Created on: Nov 25, 2015
 *      Author: Sean
 */

#include "GameStats.h"
#include <iostream>

using namespace std;

namespace risk {

GameStats::GameStats() {
}

GameStats::GameStats(Player *player) {
	players.push_back(player);
	player->Attach(this);
}

GameStats::~GameStats() {
	for(Player *player : players) {
		player->Detach(this);
	}
}

void GameStats::Update() {
}

void GameStats::addPlayer(Player *player) {
	players.push_back(player);
	player->Attach(this);
}

//void GameStats::display() {
//	cout << endl;
//	cout << "GAME STATS" << endl;
//
//	for(Player *player : players) {
//
//		cout << "Report for: " << player->getName() << endl;
//		cout << "Armies: " << player->getArmies() << endl;
//		cout << "Countries: " << player->getCountries().size() << endl;
//		cout << "Cards: " << endl;
//	}
//}

} /* namespace GameDriver */
