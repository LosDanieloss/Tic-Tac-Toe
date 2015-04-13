#pragma once

#include <iostream>

class Board
{
public:

	char board[9];
	int emptySpace;

	Board();
	~Board();
	void draw();
	void put(int position, char mark);
	bool checkAvailability(int position);
	bool checkEndGameConditions();
	bool checkPlayerWin(char mark);
	int countBlank();
};

