/*
 * GameDriver.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#include "gamedriver.h"
#include "territory.h"
#include "map.h"
#include <iostream>

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

std::vector<Player>* GameDriver::getPlayers() {
	
	return &players;
}

int GameDriver::getPhase() {
	return phase;
}

vector<Territory> GameDriver::getTerritory() {
	return allTerritory;
}

void GameDriver::setPlayers(int num) {
	string name;
	int val = getStartingArmy(num);

	cout << "\n" << endl;

	for (int i = 0; i < num; i++){
		cout << "Player " << i + 1 << ", enter your name: " << endl;

		cin.ignore();
		getline(cin, name);

		Player player = Player(val,name);
		players.push_back(player);
		
	}
	
	
	//players.push_back(player);
}

void GameDriver::setPhase(int phase) {
	this->phase = phase;
}

void GameDriver::gameSetup() {
	int num; 

	//get amount of players, create each player
	num = getNumberOfPlayers();
	//setPlayers name and armies
	setPlayers(num);
	//use RNG to choose a country for each player, can't already be taken

}

int GameDriver::getStartingArmy(int total)
{
	switch (total)
	{
	case 2: return 40;
	case 3: return 35;
	case 4: return 30;
	case 5: return 25;
	case 6: return 20;
	default: return -1;
	}
}

int GameDriver::getNumberOfPlayers()
{
	int numberOf; //Input

	cout << "\nHow many players (between 1 and 6) will be competing for world dominance? " << endl;

	while (true) {
		try {
			cin >> numberOf; //exception handeling

			if (numberOf < 1 || numberOf > 6 || cin.fail()) {
				throw 1;
			}

			return numberOf;
		}
		catch (int e) {
			if (e == 1){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a number between 1 and 6: " << endl;
			}
		}
	}
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
			//deploy(players[i]);
		cout << "Do you want to attack?" << endl;
		//if(yes)
		//cout << who do you want to attack
		cout << "Do you want to reinforce?" << endl;
			//reinforce(players[i]);

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


