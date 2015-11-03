/*
 * GameDriver.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#include "gamedriver.h"
#include "territory.h"

using namespace std;



GameDriver::GameDriver() {
	// TODO Auto-generated constructor stub

//	gameSetup();

	phase = 1;
	subphase = 0;

}

GameDriver::~GameDriver() {
	// TODO Auto-generated destructor stub
}

std::vector<Player*> GameDriver::getPlayers() {
	return players;
}

int GameDriver::getPhase() {
	return phase;
}

vector<Territory> GameDriver::getTerritory() {
	return allTerritory;
}

void GameDriver::setPlayers(Player* player) {
	players.push_back(player);
}

void GameDriver::setPhase(int phase) {
	this->phase = phase;
}


void GameDriver::gameSetup() {
	//get amount of players, create each player
	//use RNG to choose a country for each player, can't already be taken
}

void GameDriver::phaseController() {
	//cout subphase 1 = choose amount of players, randomly assign countries to players

	//after that, do this loop which goes through the subphases of deploy, attack, reinforce
	while(!winner)
		subphaseController();
}

void GameDriver::subphaseController() {
	for(int i = 0; i < players.size(); i++) {
		//player[i] does their turn
		cout << "Do you want to deploy?" << endl;
			deploy(players[i]);
		cout << "Do you want to attack?" << endl;
		//if(yes)
		//cout << who do you want to attack
		cout << "Do you want to reinforce?" << endl;
			reinforce(players[i]);

	}
}

void GameDriver::deploy() {
	// deploy armies to any of your countries
}

void GameDriver::attack() {
	// attack another country, if you wish
}

void GameDriver::reinforce() {
	//reinforce one of your other countries
}

bool GameDriver::confirm() {
	return false;
}


