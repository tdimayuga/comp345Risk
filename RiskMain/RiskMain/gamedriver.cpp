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

std::vector<Player*> GameDriver::getPlayers() {
	
	return players;
}

int GameDriver::getPhase() {
	return phase;
}

vector<Territory> GameDriver::getTerritory() {
	return allTerritory;
}

void GameDriver::setPlayers(int num) {
	string name;
	int armies = getStartingArmy(num);

	cout << "\n" << endl;

	for (int i = 0; i < num; i++){
		cout << "Player " << i+1 << ", enter your name: " << endl;

		cin.ignore();
		getline(cin, name);

		Player *player = new Player(name);
		players.push_back(player);
		PlayerView *pview = new PlayerView(player);
		
		player->addArmies(armies);

		players.push_back(player);
		playerViews.push_back(pview);
	}
	
//	phaseController();
	
}

void GameDriver::setPhase(int phase) {
	this->phase = phase;
}

void GameDriver::gameSetup() {
	
	int amtPlayers;

	amtPlayers = getNumberOfPlayers();

	setPlayers(amtPlayers);
}

int GameDriver::getStartingArmy(int total)
{
	switch (total)
	{
		case 1: return 100;
		case 2: return 40;
		case 3: return 35;
		case 4: return 30;
		case 5: return 25;
		case 6: return 20;
		default: return -1;
	}
}

void GameDriver::assignTerritories() {

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
	while(!winner)
		subphaseController();
}

void GameDriver::subphaseController() {
	for(int i = 0; i < players.size(); i++) {

		string countryName;
		string attackResponse;
		string reinforceResponse;

		cout << "Where do you want to deploy your armies?" << endl;
		cin.ignore();
		getline(cin, countryName);

		cout << "Do you want to attack? (Y/N)" << endl;
		cin.ignore();
		getline(cin, attackResponse);
		if (attackResponse == "Y")
			cout << "What country would you like to use to attack?" << endl;


		cout << "Do you want to reinforce?" << endl;
		cin.ignore();
		getline(cin, reinforceResponse);


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


