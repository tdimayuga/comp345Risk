/*
 * Player.h
 *
 *  Created on: Oct 23, 2015
 *      Author: Sean
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "territory.h"

#include <string>
#include <vector>

class Player {

private:
	std::vector<Territory> territory;
	int armies;
	int continents;
	std::string playerName;

public:
	Player();
	Player(Territory, int, std::string);
	Player(int, std::string);
	~Player();

	std::vector<Territory> getTerritory();
	int getArmies();
	int getContinents();

	void setName(std::string);
	void setTerritory(Territory);
	void addArmies(int);
	void removeArmies(int);
	void addContinents(int);

	bool attackTerritory(Territory territory, int armies);
};

#endif /* PLAYER_H_ */
