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
	if(phase == 1) {
		//players are chosen, map is chosen, countries assigned to players randomly
	}
	else if(phase == 2) {
		//round-robin phase
		//subphase 1 == deploy armies
		//subphase 2 == attack phase
		//subphase 3 == reinforce phase
		//do battle code here
		//do until there's a winner, maybe this should be a while
	}
	else {
		//winner is declared
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


