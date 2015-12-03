#pragma once

#include "ComputerPlayer.h"

class Aggressive : public ComputerPlayer
{
public:

	virtual void reinforcePhase();
	virtual void battlePhase();
	virtual void fortifyPhase();
};