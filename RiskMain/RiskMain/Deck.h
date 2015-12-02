#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <iostream>
#include <string>
#include <vector>

const int MAX_CARDS = 42;
const int NUM_TYPES = 4;
const int WILD = 2;
const int INFANTRY = 14;
const int CAVALRY = 13;
const int CANNON = 13;

class Deck {

private:


	std::vector<Card> theDeck;

public:

	Deck();
	Deck(const Deck&);

	void createDeck();
	void addCard(Card);
	bool checkValidTurnIn(int, int, int);
	void removeCard(int);
	void removeTurnCards(int, int, int);
	int getSize();
	Card getCard(int);
	Card dealCard();
	bool isEmpty();


};

#endif