#include <iostream>
#include <string>

#include "save.h"
#include "load.h"
#include "gamedriver.h"
#include "player.h"

using namespace std;

GameDriver theGD;
Load LD;



void main()
{

	theGD = GameDriver();
	LD = Load("../MapFiles/World.map");

	theGD.gameSetup();
	//phaseController



	
}
