/*
 * PlayerView.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Sean
 */

#include "PlayerView.h"
#include <iostream>
#include "Country.h"

using namespace std;

namespace risk {

PlayerView::PlayerView() {
	player = 0;
};

PlayerView::PlayerView(Player* player) {
	this->player = player;
	player->Attach(this);
}

PlayerView::~PlayerView() {
	player->Detach(this);
}

void PlayerView::Update() {
	display();
}

void PlayerView::display() {
	int armies = player->getArmies();
	int continents = player->getContinents();
	vector<Country *> countries = player->getCountries();

	cout << endl;
	cout << "Report for " << player->getName() << endl;
	cout << "Armies: " << armies << endl;
	cout << "Continents: " << continents << endl;

	cout << "Countries: " << endl;
	for(int i = 0; i < countries.size(); i++) {
		Country *country = countries.at(i);
		cout << country->getName() << "'s armies: " << country->getArmies() << endl;
	}
}

} /* namespace GameDriver */
