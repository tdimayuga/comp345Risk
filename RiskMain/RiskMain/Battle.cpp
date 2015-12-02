#include "Battle.h"
#include "Dice.h"
#include <iostream>
#include <string>

using namespace std;

extern int MAX_ATK_DICE;
extern int MAX_DEF_DICE;


Battle::Battle(int* atk, int* def)
{
	all = false;
	change = true;
	takeOver= false;
	attackBool = true; 


	attackDie = 0;
	defendDie = 0;

	attackVal = atk;
	defendVal = def;

	troop = "";
	again = "";
}
bool Battle::attack(){
	
	//create instance of dice
	Dice theDice = Dice();

	while (attackBool)
	{//stay in battle pahse while attacker whishes to attack 

		//proceed with attack phase

		//get corresponding die based on Troop strength 
		getAttackingDie();
		getDefendingDie();

		if (!all)
		{//if person is not all in, procees with this command order
			
			//system("CLS");
			
			//roll and comapre die	
			theDice.rollDice(attackDie, defendDie);
			theDice.compareDice(attackDie, defendDie, attackVal, defendVal);

			DisplayTroopStrength();
			//system("PAUSE");

			if (checkWin())
				change = true;
			else
				continueAttack();
		}
		else
		{
			theDice.rollDice(attackDie, defendDie);
			theDice.compareDice(attackDie, defendDie, attackVal, defendVal);

			if (checkWin())
			{
				DisplayTroopStrength();
				change = true;
			}
				
		}
	}

	return takeOver;
}
bool Battle::checkWin()
{//checks if attackers won or are unable to fight anymore with chosen country
	if (*attackVal > 1 && *defendVal == 0)
	{
		cout << "Attackers win!!!" << endl;
		cout << "You Have Taken Over A New Country" << endl;
		attackBool = false;
		//reinforce new area
		return true;
	}
	else if (*attackVal == 1 && *defendVal >= 1)
	{
		cout << "Defenders win!!!" << endl;
		cout << "They Have Defended Their Country" << endl;
		attackBool = false;
		return true;
	}
	return false;
}
void Battle::DisplayTroopStrength()
{
	cout << "Attackers Troop Strength: " << *attackVal << " VS Defenders Troop Strength: " << *defendVal << endl;
}
void Battle::continueAttack()
{//checks if attacker whishes to change country or continue attacking
	
	cout << "Do you wish to attack again? <YES/NO>?  ";
	cin >> again;

	if (again == "no")
	{
		cout << "Do you wish to change countries? <YES/NO>?  ";
		cin >> again;

		if (again == "yes")
			change = true;
		else
			attackBool = false;
	}
}
void Battle::getAttackingDie()
{//Gets number of attacking die / checks if atacker wants to go all in

	
	do
	{
		if (all)
		{
			if (*attackVal > MAX_ATK_DICE)
				attackDie = MAX_ATK_DICE;
			else if (*attackVal == MAX_ATK_DICE)
				attackDie = MAX_ATK_DICE - 1;
			else if (*attackVal < MAX_ATK_DICE)
				attackDie = *attackVal - 1;

			break;
		}

		cout << "choose # of troops <MAX> 3, Type allin for all-in mode: ";
		cin >> troop;

		if (troop == "allin")
		{
			all = true;
			break;
		}
		else
			attackDie = stoi(troop.c_str());//gets amount of troops, attacking

	} while ((attackDie > MAX_ATK_DICE || attackDie <= 0) || (attackDie > *attackVal));


}
void Battle::getDefendingDie()
{
	if (*defendVal >= 2)
		defendDie = 2;
	else if (*defendVal == 1)
		defendDie = 1;
}
