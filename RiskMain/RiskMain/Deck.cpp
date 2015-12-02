#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include <list>
#include <time.h>
#include <vector>

using namespace std;

Deck::Deck()
{

}
Deck::Deck(const Deck& copyDeck)
{
	for (int i = 0; i < copyDeck.theDeck.size(); i++)
	{
		theDeck.push_back(copyDeck.theDeck.at(i));
	}
}
Card Deck::getCard(int i)
{
	return theDeck.at(i);
}
int Deck::getSize()
{
	return theDeck.size();
}
bool Deck::checkValidTurnIn(int i, int j, int k)
{
	if (i > theDeck.size() || k > theDeck.size() || k > theDeck.size())
	{
		return false;
	}
	else if ((theDeck.at(i).getRank() == theDeck.at(j).getRank() && theDeck.at(k).getRank() == theDeck.at(i).getRank()) || (theDeck.at(i).getRank() == theDeck.at(j).getRank() && theDeck.at(k).getRank() == "WILD") || (theDeck.at(i).getRank() == theDeck.at(k).getRank() && theDeck.at(j).getRank() == "WILD") || (theDeck.at(k).getRank() == theDeck.at(j).getRank() && theDeck.at(i).getRank() == "WILD"))
		return true;
	else
		return false;
}
void Deck::removeCard(int j)
{

	theDeck.erase(theDeck.begin() + j);
}
void Deck::removeTurnCards(int q, int j, int k)
{
	vector<Card> copyDeck;

	for (int i = 0; i < theDeck.size(); i++)
	{
		if (j != i && q != i && k != i)
			copyDeck.push_back(theDeck.at(i));
	}

	theDeck = copyDeck;

}
void Deck::addCard(Card theCard)
{
	theDeck.push_back(theCard);
}
void Deck::createDeck()
{
	srand(time(0));

	int inf = 0;
	int cal = 0;
	int can = 0;
	int wild = 0;
	int deal = -1;

	while (theDeck.size() != MAX_CARDS)
	{
		deal = rand() % NUM_TYPES;

		switch (deal)
		{
		case 0:
			if (inf != INFANTRY){ inf++; theDeck.push_back(Card("INFANTRY")); }
		case 1:
			if (cal != CAVALRY){ cal++; theDeck.push_back(Card("CALVALRY")); }
		case 2:
			if (can != CANNON){ can++; theDeck.push_back(Card("CANNON")); }
		case 3:
			if (wild != WILD){ wild++; theDeck.push_back(Card("WILD")); }
		}
	}

}
Card Deck::dealCard()
{
	Card theCard = theDeck.front();
	theDeck.erase(theDeck.begin());
	return theCard;
}
bool Deck::isEmpty()
{
	return theDeck.empty();
}