/*
 * GameDriver.cpp
 *
 *  Created on: Oct 24, 2015
 *      Author: Sean
 */

#include "gamedriver.h"
#include "territory.h"
#include "map.h"
#include <iostream>

using namespace std;



GameDriver::GameDriver(Map map) {
	// TODO Auto-generated constructor stub

//	gameSetup();

	phase = 1;
	subphase = 0;
	winner = false;
	myMap = map;
	allTerritory = map.territories;
	turnIn = 0;
	deck.createDeck();
	//deploy();
}

GameDriver::~GameDriver() {
	// TODO Auto-generated destructor stub
}

std::vector<Player*> GameDriver::getPlayers() {
	
	return players;
}

int GameDriver::getPhase() {
	return phase;
}

vector<Territory> GameDriver::getTerritory() {
	return allTerritory;
}

void GameDriver::setPlayers(int num) {
	string name;
	int armies = getStartingArmy(num);

	cout << "\n" << endl;

	for (int i = 0; i < num - numAI ; i++){
		
		
		cout << "Player " << i+1 << ", enter your name: " << endl;
		getline(cin, name);

		Player *player = new Player(name);
		players.push_back(player);
		PlayerView *pview = new PlayerView(player);
		
		player->addArmies(armies);

		playerViews.push_back(pview);
		cout << endl;

		player->theHand.addCard(deck.dealCard());
		player->theHand.addCard(deck.dealCard());
		player->theHand.addCard(deck.dealCard());
		player->theHand.addCard(deck.dealCard());
		player->theHand.addCard(deck.dealCard());
		
	}
	

	//Set Names and Start types for Ai players
	for (int i = 0; i < numAI; i++)
	{
		
		int strategyType = 0;
		cout << "\nEnter the name for computer player " << i + 1 << ": " << endl;

		cin.ignore();
		getline(cin, name);

		cout << "Choose a strategy type:\n\t1.Random\n\t2.Defensive\n\t3.Aggressive\n" << endl;

		while (true) {
			try {
				cout << "\nSrategy type: " << endl;

				cin >> strategyType; //exception handeling

				if (strategyType > 3 || strategyType < 1 || cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw 1;
				}

				break; //if no exception thrown, while loop is exited
			}
			catch (int e) {
				cout << "The selected strategy is not valid." << endl;
			}
		}

		if (strategyType == 1) {
			Random *ran= new Random();
			AIplayers.push_back(ran);

			ran->addArmies(armies);
			ran->setName(name);
		}
		else if (strategyType == 2) {
			Defensive *def = new Defensive();
			AIplayers.push_back(def);

			def->addArmies(armies);
			def->setName(name);
		}
		else if (strategyType == 2) {

			Aggressive *agress = new Aggressive();
			AIplayers.push_back(agress);

			agress->addArmies(armies);
			agress->setName(name);

		}

	}

	assignTerritories();
	phaseController();
	system("pause");
}

void GameDriver::setPhase(int phase) {
	this->phase = phase;
}

void GameDriver::gameSetup() {
	
	int amtPlayers;

	amtPlayers = getNumberOfPlayers();
	
	cin.clear(); // reset failbit
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	setPlayers(amtPlayers);
}

int GameDriver::getStartingArmy(int total)
{
	switch (total)
	{
		case 1: return 100;
		case 2: return 40;
		case 3: return 35;
		case 4: return 30;
		case 5: return 25;
		case 6: return 20;
		default: return -1;
	}
}

void GameDriver::assignTerritories() {

	int total = 0;
	bool sort = true;

	while (sort)
	{
		for (Player *player : players)
		{
			int random = (rand()*rand() % allTerritory.size());

			if (total < allTerritory.size())
			{
				while (allTerritory[random].getOwner() != "")
				{
					random = (rand()*rand() % allTerritory.size());
				}

				allTerritory[random].setOwner(player->getName());

				//All players must have 1 army value on each territory
				allTerritory[random].setArmies(1);
				player->addArmies(-1);

				player->setTerritory(allTerritory[random]);

				

				total++;//increment for total territories
				
				system("pause");
			}
			else
			{
				sort = false;
				break;
			}
		}


		for (ComputerPlayer *AI : AIplayers)
			{
				int random = (rand()*rand() % allTerritory.size());

				if (total < allTerritory.size())
				{
					while (allTerritory[random].getOwner() != "")
					{
						random = (rand()*rand() % allTerritory.size());
					}

					allTerritory[random].setOwner(AI->getName());
					AI->setTerritory(allTerritory[random]);

					//All players must have 1 army value on each territory
					allTerritory[random].setArmies(1);
					AI->addArmies(-1);

					total++;//increment for total territories

					system("pause");
				}
				else
				{
					sort = false;
					break;
				}
			}
	}
	
}

int GameDriver::getNumberOfPlayers()
{
	int numberOf = 0; //Input
	int numberAi = 0;
	numAI = 0;

	cout << "\nHow many players (between 1 and 6) will be competing for world dominance? " << endl;

	while (true) {
		try {
			cin >> numberOf; //exception handeling

			if (numberOf < 1 || numberOf > 6 || cin.fail()) {
				throw 1;
			}

			break;
		}
		catch (int e) {
			if (e == 1){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter a number between 1 and 6: " << endl;
			}
		}
	}

	if (numberOf < 6) {

		cout << "\nHow many AI players (between 0 and" << 6 - numberOf << ") will be competing for world dominance? " << endl;

		while (true) {
			try {
				cin >> numberAi; //exception handeling

				if (numberAi < 0 || numberAi > (6 - numberOf) || cin.fail()) {
					throw 1;
				}

				numAI = numberAi;
				break;
			}
			catch (int e) {
				if (e == 1){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter a number (between 0 and " << 6 - numberOf << ")" << endl;
				}
			}
		}
	}

	return numberAi + numberOf;
}

void GameDriver::phaseController() {
	while(!winner)
		subphaseController();
}

void GameDriver::subphaseController() {
	

	for(Player *player : players) {
		string attackResponse;
		string reinforceResponse;
		string fortifyResponse;

		//Reinforce
		while (true) 
		{
			cout << "Do you want to reinforce? (Y/N)" << endl;

			try {
				cin >> reinforceResponse; //exception handeling

				if (reinforceResponse != "Y" || reinforceResponse != "y" || reinforceResponse != "n" || reinforceResponse != "N") {
					throw 1;
				}

				
			}
			catch (int e) {
				if (e == 1){
					cin.clear();
					cout << "Please Try Again: " << endl;
				}
			}

			if (reinforceResponse == "Y" || reinforceResponse == "y")
			{
				reinforce(player);
				break;
			}
			else
				break;
		}

		//attack
		while (true)
		{
			cout << "Do you want to attack? (Y/N)" << endl;

			try {
				cin >> attackResponse; //exception handeling

				if (attackResponse != "Y" || attackResponse != "y" || attackResponse != "n" || attackResponse != "N") {
					throw 1;
				}


			}
			catch (int e) {
				if (e == 1){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please Try Again: " << endl;
				}
			}

			if (attackResponse == "Y" || attackResponse == "y")
			{
				attack(player);
				break;
			}
			else
				break;
		}


		//fortify
		while (true)
		{
			cout << "Do you want to fortify? (Y/N)" << endl;

			try {
				cin >> fortifyResponse; //exception handeling

				if (attackResponse != "Y" || fortifyResponse != "y" || fortifyResponse != "n" || fortifyResponse != "N") {
					throw 1;
				}


			}
			catch (int e) {
				if (e == 1){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please Try Again: " << endl;
				}
			}

			if (fortifyResponse == "Y" || fortifyResponse == "y")
			{
				fortify(player);
				break;
			}
			else
				break;
		}
	}

}

void GameDriver::deploy() {
	//Deploy starting army
	for (Player *player : players) {
		string countryName;

		cout << "Where do you want to deploy your armies?" << endl;
		getline(cin, countryName);
	}
}

void GameDriver::attack(Player *player) {
	// attack another country, if you wish
	cout << "What country would you like to use to attack?" << endl;

	cout << "attaking\n";
}

void GameDriver::reinforce(Player *player) {
	//reinforce one of your other countries
	cout << "reinforcing\n";

	int units = 0;
	int cBonus = 0;
	int terrBonus = 0;

	units += player->getArmies(); // get army value
	cBonus = getCardBonus(player);// get card bonuses
	terrBonus = (player->getTerritory().size() / 3 );
	// get continent bonus

	units += cBonus;
	units += terrBonus;

	while (units > 0)
	{
		int index = getReinforcingIndex(player);
		int val = getReinforceValue(units);

		units -= val;


		player->getTerritory().at(index).setArmies(player->getTerritory().at(index).getArmies() + val);//set troops on target territory

		cout << "\n" << player->getTerritory().at(index).getName() << " now has " <<  player->getTerritory().at(index).getArmies() <<  " units.\n" << endl; //ouput the change
	}

	player->removeArmies(player->getArmies());// get rid of all troops in player
}

int GameDriver::getReinforceValue(int num)
{
	int add;

	while (true) {
		cout << "\nEnter the amount of units you want to reinforce with (" << num << " units left): " << endl;

		try {
			cin >> add; //will throw exception if input isn't an int 

			if (add > num) {
				throw 1;  //will throw exception if country in the list isn't in the list
			}

			if (add < 1 || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw 2;
			}

			break; //if no exception thrown, while loop is exited
		}
		catch (int e) {
			if (e == 1) {
				cout << "You don't have enough units for that." << endl;
			}

			else {
				//invalid message
				cout << "The selected amount is not valid." << endl;
			}
		}
	}//end while loop

	return add;
}

int GameDriver::getReinforcingIndex(Player* player)
{
	int num = -1;
	while (true) {

		for (int i = 0; i < player->getTerritory().size(); i++)
		{
			cout << i + 1 << ") " << player->getTerritory().at(i).getName() << " Troops: " << player->getTerritory().at(i).getArmies() << endl;
		}

		try {
			//get the country the user wants to move units to, the index of the countries owned by the player
			cout << "\nNumber of the country to fortify: " << endl;

			cin >> num; //exception handeling

			if (num > player->getTerritory().size() || num < 1 || cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw 2;  //will throw exception if country in the list isn't in the list
			}

			break; //if no exception thrown, while loop is exited
		}
		catch (int e) {
			//invalid message
			cout << "The selected country is not valid." << endl;
		}
	}
	return num -1;

}

int GameDriver::getTurnInUnits()
{
	switch (turnIn)
	{
	case 1: return 4;
	case 2: return 6;
	case 3: return 8;
	case 4: return 10;
	case 5: return 12;
	case 6: return 15;
	}

	if (turnIn > 6)
		return (15 + (5 * (turnIn - 6)));
}

int GameDriver::getCardBonus(Player* player)
{
	int cards[3];
	bool hand = true;
	bool check = false;
	bool turn = false;
	int addUnits = 0;
	string answer;

	while (true)
	{

		if (player->theHand.getSize() >= 1)
		{
			cout << "\n Here Are Your Cards: \n" << endl;

			showCards(player);


			cout << "\n Would you like to hand in your cards \n" << endl;
			cin >> answer;

			if (!answer.compare("no")){
				break;
			}
			else if (player->theHand.getSize() < 3 /*change to global const*/)
			{
				cout << "\n You do not have a Minimum of 3 cards \n" << endl;
				break;
			}


			do
			{
				cout << "\n Please Select 3 Cards To Hand In \n"  << endl;
				for (int i = 0; i < 3 /*change to global const*/; i++)
				{
					cin >> cards[i];
				}

				check = player->theHand.checkValidTurnIn(cards[0] - 1, cards[1] - 1, cards[2] - 1);

				if (check)
				{
					player->theHand.removeTurnCards(cards[0] - 1, cards[1] - 1, cards[2] - 1);

					turnIn++;
					addUnits += getTurnInUnits();

					if (player->theHand.getSize() >= 3)
					{
						cout << "\n Would You Like To Hand In Again ?? \n" << endl;
						cin >> answer;

						if (!answer.compare("no")){
							hand = false;
						}
					}
					else
					{
						hand = false;
					}
				}
				else
				{
					cout << "\n Invalid Input yould you like to try again? \n" << endl;
					cin >> answer;


					if (!answer.compare("no")){
						hand = false;
						break;
					}
				}

			} while (hand);

			return addUnits;
		}
		else
		{
			cout << "\n You Have No Cards \n" << endl;
			return addUnits;
		}
	}

}

void GameDriver::showCards(Player* player)
{
	for (int i = 0; i < player->theHand.getSize(); i++)
		cout << i + 1 << ") " << player->theHand.getCard(i).getRank() << " \n" << endl;
}

void GameDriver::fortify(Player *player) {
	//fortify one of your other countries
	cout << "fotifying\n";
}


