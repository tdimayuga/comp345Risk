//
//  Battle.h
//  RISK-Mast
//
//  Created by Bhavik Patel on 2015-03-22.
//  Copyright (c) 2015 Bhavik,Edi,Geo,Devin. All rights reserved.
//

#ifndef Battle_h
#define Battle_h

#include <string>
using namespace std;

class Battle{

public:

	bool all;
	bool change;
	bool attackBool;

	int attackDie;
	int defendDie;
	int* attackVal;
	int* defendVal;

	string troop;
	string again;

	Battle();

	void attack();
	void getCountryToAttack();
	void getAttackingCountry();
	void getAttackingDie();
	void getDefendingDie();
	void chooseAttacking();
	void continueAttack();
	void DisplayTroopStrength();
	bool checkWin();
};
#endif
