/*
 * GameDriver.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#include "gamedriver.h"
#include <iostream>

using namespace std;

namespace risk {

GameDriver::GameDriver() {
	// TODO Auto-generated constructor stub

//	gameSetup();
	winner = false;
	phase = 1;

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

Country* GameDriver::getCountries() {
	return allCountries;
}

int GameDriver::getAmtPlayers() {
	return players.size();
}

void GameDriver::addPlayers(Player* player) {
	players.push_back(player);
}

void GameDriver::setPhase(int phase) {
	this->phase = phase;
}

void GameDriver::setCountries() {
	//initialize all the possible countries in the world
}

void GameDriver::gameSetup() {
	//get amount of players
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

void GameDriver::deploy(Player* player) {
	// deploy armies to any of your countries
	//player add armies
}

void GameDriver::attack(Player* player) {
	// attack another country, if you wish
	// player attack other country
}

void GameDriver::reinforce(Player* player) {
	//reinforce one of your other countries
	//player reinforce country
}

bool GameDriver::confirm() {
	return false;
}

} /* namespace GameDriver */
