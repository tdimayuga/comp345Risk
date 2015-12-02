#pragma once

#include "ComputerPlayer.h"


class Random : public ComputerPlayer
{
public:

	virtual void reinforcePhase();
	virtual void battlePhase();
	virtual void fortifyPhase();
};