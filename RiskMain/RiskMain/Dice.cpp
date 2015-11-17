#include <iostream>
#include "Dice.h"
#include <time.h>
#include <ctime>
#include <algorithm>
#include <functional>  

using namespace std;

extern int MAX_ATK_DICE;
extern int MAX_DEF_DICE;


Dice::Dice()
{

}
void Dice::rollDice(int atck, int def)
{//Rolls and stores the die for attackers and defenders

	int die = 0;
	for (int i = 0; i< atck; i++)
	{ //store the die rolled in appropriate arrays
		
		die = (rand() % 6) + 1;//random number between 1-6

			atkArray[i] = die;	
	}

	for (int i = 0; i< def; i++)
	{ //store the die rolled in appropriate arrays

		die = (rand() % 6) + 1;//random number between 1-6

		defArray[i] = die;
	}
	
}
//Method that compares dice rolls with highest to highest and second highest to second highest
void Dice::compareDice(int atk, int def, int* aVal, int* dVal){
	int num = 0;

	//sorts dice array in decending order 
	sort(atkArray, atkArray + atk, greater<int>());
	sort(defArray, defArray + def, greater<int>());


	//Prints Array of Dice numbers 
	cout << "The attackers die are : ";
	for (int i = 0; i < atk; i++){
		cout << atkArray[i];
		if ((i + 1) != atk)
			cout << " , ";
		else
			cout << endl;
	}
	cout << "The defenders die are : ";
	for (int i = 0; i < def; i++){
		cout << defArray[i];
		if ((i + 1) != def)
			cout << " , ";
		else
			cout << endl;
	}

	if (atk > def)
		num = def;
	else if (def > atk)
		num = atk;
	else
		num = atk;
		
	
		for (int i = 0; i < num; i++)
		{
			cout << " comparing attack: " << atkArray[i] << " and defense: " << defArray[i] << endl;
			
			if (atkArray[i] > defArray[i])
			{
				cout << " Attackers win minus 1 to defense!" << endl;
				//defense troops - 1
				--*dVal;
			}
			else
			{
				cout << " Defenders win minus 1 to Attackers!" << endl;
				//attack troops - 1
				--*aVal;
			}
		}

}
