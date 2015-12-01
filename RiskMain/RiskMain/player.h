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

#include <string>
#include <vector>

class Player : public Subject {

private:
	std::vector<Territory> territory;
	int armies;
	int continents;
	std::string playerName;
	int battlesWon;

public:
	Player();
	Player(std::string);
	Player(Territory, int, std::string);
	Player(int, std::string);
	~Player();

	std::vector<Territory> getTerritory();
	int getArmies();
	int getContinents();
	int getBattlesWon();
	std::string getName();

	void setName(std::string);
	void setTerritory(Territory);
	void addArmies(int);
	void removeArmies(int);
	void addContinents(int);
	void addBattlesWon(int);

	bool attackTerritory(Territory territory, int armies);
};

#endif /* PLAYER_H_ */
