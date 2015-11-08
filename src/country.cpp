/*
 * Country.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#include "country.h"
#include "player.h"

using namespace std;

namespace risk {

Country::Country() {
	// TODO Auto-generated constructor stub
	owner = 0;
	armies = 0;
}

Country::Country(Player* owner, int armies, std::string name) {
	this->owner = owner;
	this->armies = armies;
	this->name = name;
}

Country::~Country() {
	// TODO Auto-generated destructor stub
}

//Country* Country::getAttackable() {
//	return attackable;
//}

Player* Country::getOwner() {
	return owner;
}

int Country::getArmies() {
	return armies;
}

std::string Country::getName() {
	return name;
}

//void Country::setAttackable(Country countries[]) {
//
//}

void Country::setOwner(Player* owner) {
	this->owner = owner;
}

void Country::setArmies(int armies) {
	this->armies = armies;
}

} /* namespace GameDriver */
