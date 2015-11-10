#include <iostream>
#include <string>
#include <vector>

#include "save.h"
#include "load.h"
#include "gamedriver.h"
#include "player.h"
#include "map.h"

using namespace std;

GameDriver driver;
Load LD;
Map gameMap;
vector<Player>* players;

void main()
{

	driver = GameDriver();

	LD = Load("../MapFiles/World.map");
	gameMap = LD.getMap();



	driver.gameSetup();

	//players = driver.getPlayers();
	
	system("Pause");

	//phaseController

	//Code uploaded by Sean - Sample Main
	// 	GameDriver driver;

	// int defaultArmy = 10;

	// Player player1(defaultArmy, "Sean");
	// Country canada(&player1, defaultArmy, "Canada");
	// player1.setCountry(&canada);

	// Player player2(defaultArmy, "Trisha");
	// Country usa(&player2, defaultArmy, "USA");
	// player2.setCountry(&usa);

	// driver.addPlayers(&player1);
	// driver.addPlayers(&player2);

	// std::vector<Player*> players = driver.getPlayers();

	// cout << "Display of the values." << endl;

	// for(int i = 0; i < players.size(); i++) {
	// 	cout << "Player's name: "<< players[i]->getName() << endl;
	// 	cout << "Player's country: " << players[i]->getCountries()[0]->getName() << endl;
	// 	cout << "Player's army: " << players[i]->getArmies() << endl;
	// 	cout << "To be sure it's the right owner: " << players[i]->getCountries()[0]->getOwner()->getName() << endl;
	// 	cout << "=========" << endl;
	// }
	


	
}
