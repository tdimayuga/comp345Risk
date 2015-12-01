/*
 * WorldStats.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#include "WorldStats.h"
#include <iostream>

	void WorldStats::Update() {
		GameStatsDecorator::display();
		display();
	}

	WorldStats::~WorldStats() {
		for(Player *player : players)
			player->Detach(this);
	}

	void WorldStats::display() {

		double totalCountries = 0;
		for(Player *player : players)
			totalCountries += player->getTerritory().size();

		cout << endl;
		cout << "WORLD STATS" << endl;
		cout << "Total amount of countries: " << totalCountries << endl;
		for(Player *player : players) {
			double percent = 0;
			cout << player->getName() << " owns " <<
					player->getTerritory().size() << " country(ies)" << endl;
			percent = player->getTerritory().size() / totalCountries * 100.0;

			cout << player->getName() << " owns " <<
					percent << "%." << endl;
 		}
	}
