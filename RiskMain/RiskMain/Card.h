#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {

private:
	std::string rank;

public:

	//Constructors
	Card();
	Card(std::string);

	//Getters
	std::string getRank();
};

#endif