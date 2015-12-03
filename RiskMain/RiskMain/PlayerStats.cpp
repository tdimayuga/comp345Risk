/*
 * PlayerStats.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#include "PlayerStats.h"
#include <iostream>

	PlayerStats::PlayerStats(Player *player) {
		players.push_back(player);
		player->Attach(this);
	}

	PlayerStats::PlayerStats(GameStats *gameStats) {
		for(Player *player : gameStats->getPlayers()) {
			player->Detach(gameStats);
			player->Attach(this);
		}
		players = gameStats->getPlayers();
	}

	PlayerStats::~PlayerStats() {
		for(Player *player : players)
			player->Detach(this);
	}

	void PlayerStats::Update() {
		display();
	}

	void PlayerStats::display() {
			cout << endl;
			cout << "GAME STATS" << endl;

			for(Player *player : players) {

				cout << "Report for: " << player->getName() << endl;
				cout << "Armies: " << player->getArmies() << endl;
				cout << "Countries: " << player->getTerritory().size() << endl;
				cout << "Cards: " << endl;
			}
	}