#ifndef DICE_H
#define DICE_H
 
class Dice
{

public:

	
	int defArray[2];
	int atkArray[3];

	Dice();

	void resetDice();
	void compareDice(int, int,int*,int*);
	void rollDice(int,int);

};
#endif