//============================================================================
// Name        : Assignment1COMP345GameDriver.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "country.h"
#include "player.h"
#include "gamedriver.h"

using namespace std;
using namespace risk;

int main() {
	//	GameDriver driver;

		Country* country;
		Player player1(country, 10, "Sean");

		int i = player1.getArmies();

		std::cout << "HELLO!!" << endl;
		std::cout << i << endl;

		return 0;
}
