/*
 * PlayerView.cpp
 *
 *  Created on: Nov 8, 2015
 *      Author: Sean-Frankel Gaon Canlas
 */

#include "PlayerView.h"
#include <iostream>

using namespace std;

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

	cout << endl;
	cout << "Report for " << player->getName() << endl;
	cout << "Armies: " << armies << endl;

	if (player->getTerritory().size() != 0)
	{
		cout << "Countries: ";

		for (Territory t : player->getTerritory()) {
			cout << t.getName() + " ";
		}
		cout << endl;
	}
}
