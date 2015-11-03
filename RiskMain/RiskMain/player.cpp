/*
 * Player.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: Sean
 */

#include "player.h"
#include "territory.h"

#include <vector>

using namespace std;

Player::Player() {
	// TODO Auto-generated constructor stub
	armies = 0;
	continents = 0;
	playerName = "";
}

Player::Player(Territory territory, int armies, std::string playerName) {
	this->territory.push_back(territory);
	this->armies += armies;
	continents = 0;
	this->playerName = playerName;
}

Player::~Player() {
	// TODO Auto-generated destructor stub

}

std::vector<Territory> Player::getTerritory() {
	return territory;
}

int Player::getArmies() {
	return armies;
}

int Player::getContinents() {
	return continents;
}

void Player::setTerritory(Territory territory) {
	this->territory.push_back(territory);
}

void Player::addArmies(int armies) {
	armies += armies;
}

void Player::removeArmies(int armies) {
	this-> armies -= armies;
}

void Player::addContinents(int continent) {
	continents += continent;
}

bool Player::attackTerritory(Territory territory, int armies) 
{
	territory.setArmies(armies);
	return true;
}
