/*
 * Player.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: Sean
 */

#include "player.h"
#include "country.h"

#include <vector>

using namespace std;

namespace risk {

Player::Player() {
	// TODO Auto-generated constructor stub
	armies = 0;
	continents = 0;
	playerName = "";
}

Player::Player(Country* country, int armies, std::string playerName) {
	countries.push_back(country);
	this->armies += armies;
	continents = 0;
	this->playerName = playerName;
}

Player::~Player() {
	// TODO Auto-generated destructor stub

}

std::vector<Country*> Player::getCountries() {
	return countries;
}

int Player::getArmies() {
	return armies;
}

int Player::getContinents() {
	return continents;
}

void Player::setCountry(Country* country) {
	countries.push_back(country);
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

bool Player::attackCountry(Country country, int armies) {
	country.setArmies(armies);
	return true;
}

} /* namespace GameDriver */
