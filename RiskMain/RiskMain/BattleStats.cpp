/*
 * BattleStats.cpp
 *
 *  Created on: Nov 26, 2015
 *      Author: Sean
 */

#include "BattleStats.h"
#include <iostream>

void BattleStats::Update() {
	display();
}

BattleStats::~BattleStats() {
	for(Player *player : players)
		player->Detach(this);
}

void BattleStats::display() {
	system("cls");
	cout << endl;
	cout << "BATTLE STATS" << endl;
	for(Player *player : players) {
		cout << "Battles won for: " << player->getName() << endl;
		cout << "Wins: " << player->getBattlesWon() << endl;
	}
}
