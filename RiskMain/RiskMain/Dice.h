#ifndef DICE_H
#define DICE_H
 
class Dice
{

public:

	
	int defArray[3];
	int atkArray[2];

	Dice();

	void compareDice(int, int,int*,int*);
	void rollDice(int,int);

};
#endif