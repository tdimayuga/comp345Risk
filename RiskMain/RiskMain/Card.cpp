#include <iostream>
#include <string>
#include "Card.h"

using namespace std;


//Constructors
Card::Card()
{
	rank = "NA";
}
Card::Card(string val)
{
	rank = val;
}
//Getters
string Card::getRank()
{
	return rank;
}