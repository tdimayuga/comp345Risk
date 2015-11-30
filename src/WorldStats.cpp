/*
 * WorldStats.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#include "WorldStats.h"
#include <iostream>

namespace risk {

	void WorldStats::Update() {
		display();
	}

	WorldStats::~WorldStats() {
		for(Player *player : players)
			player->Detach(this);
	}

	void WorldStats::display() {

		double totalCountries = 0;
		for(Player *player : players)
			totalCountries += player->getCountries().size();

		cout << endl;
		cout << "WORLD STATS" << endl;
		cout << "Total amount of countries: " << totalCountries << endl;
		for(Player *player : players) {
			double percent = 0;
			cout << player->getName() << " owns " <<
					player->getCountries().size() << " country(ies)" << endl;
			percent = player->getCountries().size() / totalCountries * 100.0;

			cout << player->getName() << " owns " <<
					percent << "%." << endl;
 		}
	}

} /* namespace risk */
