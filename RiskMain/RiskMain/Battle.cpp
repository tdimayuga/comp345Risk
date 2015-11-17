#include "Battle.h"
#include "Dice.h"
#include <iostream>
#include <string>

using namespace std;

int theATK = 100;//temp variables
int theDEF = 68;//temp variables

extern int MAX_ATK_DICE;
extern int MAX_DEF_DICE;


Battle::Battle()
{
	all = false;
	change = true;
	attackBool = true; 


	attackDie = 0;
	defendDie = 0;

	attackVal = NULL;
	defendVal = NULL;

	troop = "";
	again = "";
}

void Battle::attack(){
	
	//create instance of dice
	Dice theDice = Dice();

	while (attackBool)
	{//stay in battle pahse while attacker whishes to attack 

		chooseAttacking();
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


}
bool Battle::checkWin()
{//checks if attackers won or are unable to fight anymore with chosen country
	if (*attackVal > 1 && *defendVal == 0)
	{
		cout << "Attackers win!!!" << endl;
		cout << "You Have Taken Over A New Country" << endl;
		//reinforce new area
		return true;
	}
	else if (*attackVal == 1 && *defendVal >= 1)
	{
		cout << "Defenders win!!!" << endl;
		cout << "They Have Defended Their Country" << endl;
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
			else if (*attackVal = MAX_ATK_DICE)
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
void Battle::chooseAttacking()
{//choose or change countries to attak with/against

	if (change)
	{//if person wants to change countries to attack or attack with, asks for user input again
		getAttackingCountry();

		system("PAUSE");

		getCountryToAttack();

		system("PAUSE");

		change = !change;
		all = false;
	}

}
void Battle::getCountryToAttack()
{//Populates defending troops from selected country to attack

	cout << "Now select an adjacent country to attack" << endl;

	defendVal = &theDEF;//using temp variable untill "player & Map" classes
}
void Battle::getAttackingCountry()
{//Populates attaking troops from one's own country

	cout << "Please Select one of your own countries to attack with. " << endl;

	attackVal = &theATK;//using temp variable untill "player & Map" classes
}