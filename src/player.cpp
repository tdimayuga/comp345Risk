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
	battlesWon = 0;
}

Player::Player(int armies, std::string playerName) {
	this->armies = 10;
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

std::string Player::getName() {
	return playerName;
}

int Player::getBattlesWon() {
	return battlesWon;
}

void Player::addWin() {
	battlesWon += 1;
}

void Player::setCountry(Country* country) {
	countries.push_back(country);

	Notify();
}

void Player::addArmies(int armies) {
	this->armies += armies;

	Notify();
}

void Player::removeArmies(int armies) {
	this->armies -= armies;

	Notify();
}

void Player::addContinents(int continent) {
	continents += continent;

	Notify();
}

bool Player::attackCountry(Country country, int armies) {
	country.setArmies(armies);

	Notify();

	return true;
}

} /* namespace GameDriver */
