#pragma once

#include "Player1.h"

class Turn
{
public:

	int position;
	Player1 *player;

	Turn();
	~Turn();
	void readMove();
	void renderTurnInfo();
};

