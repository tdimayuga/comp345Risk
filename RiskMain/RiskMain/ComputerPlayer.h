#pragma once

#include "Player.h"
//#include "Reinforce.h"
#include <time.h>

class ComputerPlayer : public Player
{
protected:
	int randomCountry;
	int randomUnits;
	int randomTarget;
	int reinforcementUnits;
	bool computerPlayer;
	//Reinforce reinforceComputer;

public:
	void play();
	void setup();
	virtual void reinforcePhase() = 0;
	virtual void battlePhase() = 0;
	virtual void fortifyPhase() = 0;
};

