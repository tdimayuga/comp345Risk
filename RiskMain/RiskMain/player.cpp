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
	battlesWon = 0;
}

Player::Player(string name) {
	armies = 0;
	playerName = name;
	battlesWon = 0;
}

Player::Player(int val, string name){
	armies = val;
	playerName = name;
	battlesWon = 0;
}

Player::Player(Territory territory, int armies, std::string playerName) {
	this->territories.push_back(territory);
	armies = 0;
	this->armies += armies;
	continents = 0;
	this->playerName = playerName;
	battlesWon = 0;
}

Player::~Player() {
	// TODO Auto-generated destructor stub

}

std::vector<Territory> Player::getTerritories() {
	return territories;
}

int Player::getArmies() {
	/*for (Territory terr : territories) {
		armies += terr.getArmies();
	}*/
	return armies;
}

int Player::getContinents() {
	return continents;
}

int Player::getBattlesWon() {
	return battlesWon;
}

std::string Player::getName() {
	return playerName;
}

void Player::setArmies(int i, int v){
	this->territories.at(i).setArmies(v);
}

void Player::addBattlesWon(int win) {
	battlesWon += 1;
}

void Player::setName(string name){
	playerName = name;
}
void Player::setTerritory(Territory territory) {
	this->territories.push_back(territory);
	
	Notify();
}

void Player::addArmies(int armies) {
	this->armies += armies;
	
	Notify();
}

void Player::removeArmies(int armies) {
	this-> armies -= armies;
	
	Notify();
}

void Player::addContinents(int continent) {
	continents += continent;
	
	Notify();
}

bool Player::attackTerritory(Territory territory, int armies) 
{
	territory.setArmies(armies);
	return true;
}

bool Player::ownsTerritory(std::string countryName) {
	for (Territory terr : territories) {
		if (terr.getName() == countryName)
			 return true;
		else
			 return false;
		
	}
}

Territory Player::getTerritory(string name)
{
	for (int i = 0; i < territories.size(); i++)
	{
		if (territories.at(i).getName() == name)
			return territories.at(i);
	}
}

void Player::removeTerritory(string name)
{
	for (int i = 0; i < territories.size(); i++)
	{
		if (territories.at(i).getName() == name)
			territories.erase(territories.begin() + i);
	}
}