/*
 * GameDriver.h
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#ifndef GAMEDRIVER_H_
#define GAMEDRIVER_H_

#include "territory.h"
#include "player.h"
#include "PlayerView.h"
#include "map.h"
#include "Deck.h"
#include "Card.h"
#include "ComputerPlayer.h"
#include "Aggressive.h"
#include "Random.h"
#include "Defensive.h"
#include "Battle.h"
#include "GameStats.h"


class GameDriver {

	std::vector<Player*> players;
	std::vector<PlayerView*> playerViews;
	std::vector<ComputerPlayer*> AIplayers;
	int phase;
	int subphase;
	int numAI;
	int turnIn;

	Map myMap;
	std::vector<Territory> allTerritory;
	bool winner;
	bool getCard;
	Deck deck;

	GameStats *gameStats;

public:
	GameDriver(Map map);
	~GameDriver();

	std::vector<Player*> getPlayers();
	int getPhase();
	int getNumberOfPlayers();
	int getStartingArmy(int);
	
	std::vector<Territory> getTerritory();
	Territory getTerritory(std::string);

	void setPlayers(int);
	void setPhase(int);
	void assignTerritories();
	
	void gameSetup();
	void phaseController();
	void subphaseController();

	
	void deploy();
	
	Player* getPlayer(std::string);
	void attack(Player*);
	int getAttackingCountryIndex(Player*);
	std::string getDefendingCountryIndex(Territory);

	//Reinforce
	void reinforce(Player*);
	void showCards(Player*);
	int getTurnInUnits();
	int getCardBonus(Player*);
	int getReinforcingIndex(Player*);
	int getReinforceValue(int);
	int getDestinationFortifyingIndex(Player*);
	int getSourceFortifyingValue(int);
	int getSourceFortifyingIndex(Player*, int);
	//int getDestinationFortifyingValue(int);
	
	void fortify(Player*);
	bool checkWinner();
};


#endif /* GAMEDRIVER_H_ */
