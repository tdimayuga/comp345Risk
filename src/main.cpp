//============================================================================
// Name        : Assignment1COMP345GameDriver.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Risk in C++, Ansi-style
//============================================================================

#include <iostream>

#include "country.h"
#include "player.h"
#include "gamedriver.h"
#include "PlayerView.h"
#include "GameStats.h"
#include "BattleStats.h"
#include "WorldStats.h"
#include "PlayerStats.h"

#include <iostream>

using namespace std;
using namespace risk;

int main() {
		GameDriver driver;

		int defaultArmy = 10;

		Player *player1 = new Player(10, "Sean");
		Country canada(player1, 10, "Canada");
		player1->setCountry(&canada);
//		PlayerView *p1view = new PlayerView(player1);

		Player *player2 = new Player(defaultArmy, "Trisha");
		Country usa(player2, defaultArmy, "USA");
		player2->setCountry(&usa);
//		PlayerView *p2view = new PlayerView(player2);

		driver.addPlayers(player1);
		driver.addPlayers(player2);

		GameStats *gameStats = new PlayerStats(player1);
		gameStats->addPlayer(player2);

		player1->addArmies(150);

		gameStats = new BattleStats(gameStats);
		player2->addArmies(20);

		gameStats = new WorldStats(gameStats);
		player1->addArmies(0);

		gameStats = new PlayerStats(gameStats);
		gameStats->addPlayer(player2);

		player1->addArmies(0);

		return 0;
}
