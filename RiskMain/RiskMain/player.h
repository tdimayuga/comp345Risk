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
	int battlesWon;
	std::string playerName;
	

public:
	Deck theHand;

	Player();
	Player(std::string);
	Player(Territory, int, std::string);
	Player(int, std::string);
	~Player();

	std::vector<Territory> getTerritories();
	Territory getTerritory(std::string);
	int getArmies();
	int getContinents();
	int getBattlesWon();
	std::string getName();

	void removeTerritory(std::string);
	void setArmies(int,int);
	void setName(std::string);
	void setTerritory(Territory);
	void addArmies(int);
	void removeArmies(int);
	void addContinents(int);
	void addBattlesWon(int);

	bool attackTerritory(Territory territory, int armies);
	bool ownsTerritory(std::string countryName);
	
};

#endif /* PLAYER_H_ */
