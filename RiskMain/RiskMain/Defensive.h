#pragma once

#include "ComputerPlayer.h"

class Defensive : public ComputerPlayer
{
public:

	virtual void reinforcePhase();
	virtual void battlePhase();
	virtual void fortifyPhase();
};