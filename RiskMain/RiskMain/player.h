/*
 * Player.h
 *
 *  Created on: Oct 23, 2015
 *      Author: Sean-Frankel Gaon Canlas
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "territory.h"
#include "Subject.h"
#include "Deck.h"
#include <string>
#include <vector>

class Player : public Subject {

private:
	std::vector<Territory> territories;
	int armies;
	int continents;
	std::string playerName;
	

public:
	Deck theHand;

	Player();
	Player(std::string);
	Player(Territory, int, std::string);
	Player(int, std::string);
	~Player();

	std::vector<Territory> getTerritories();
	int getArmies();
	int getContinents();
	std::string getName();

	void setName(std::string);
	void setTerritory(Territory);
	void addArmies(int);
	void removeArmies(int);
	void addContinents(int);

	bool attackTerritory(Territory territory, int armies);
	bool ownsTerritory(std::string countryName);
	
};

#endif /* PLAYER_H_ */
