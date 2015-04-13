// xoxoxo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Board.h"
#include "Turn.h"
#include "Player1.h"
#include "AI.h"

bool checkEndGameConditions(Board *b){
	if (b->emptySpace == 0 || b->checkEndGameConditions())
		return true;
	else
		return false;
}

bool checkPat(Board *b){
	if (b->emptySpace == 0)
		return true;

	return false;
}

void renderPat(){
	system("cls");
	std::cout << "======================================" << std::endl;
	std::cout << "      The game ends with no winner" << std::endl;
	std::cout << "======================================" << std::endl;
}

void renderWinner(Player1 *p){
	system("cls");
	std::cout << "=================================" << std::endl;
	std::cout << "   And the Winner is " << p->name << std::endl;
	std::cout << "=================================" << std::endl;
}

void renderCompWinner(){
	system("cls");
	std::cout << "=================================" << std::endl;
	std::cout << "      And the Winner is AI "<< std::endl;
	std::cout << "=================================" << std::endl;
}

int _tmain(int argc, _TCHAR* argv[])
{

	bool playerVsPlayerMode = false;
	bool endGame = false;

	Player1 *player1, *player2;
	player1 = new Player1("playerOne", 'x');
	player2 = new Player1("playerTwo", 'o');

	AI *computerPlayer = new AI();

	Board *b;
	b = new Board();

	Turn *t;
	t = new Turn();
	t->player = player1;

	std::cout << "Choose what mode do u wanna play ;-) " << std::endl << "Type 1 to select Player vs Player" << std::endl
		<< "Type 2 to select Player vs AI" << std::endl;
	
	int mode;
	std::cin >> mode;

	playerVsPlayerMode = (mode == 1) ? true : false;

	system("cls");
	b->draw();

	// main loop of a game
	if (playerVsPlayerMode){
		while (1){
			t->readMove(); // write info on whos turn is right now and geather int from input

			// loop while user input bad position
			while (!(b->checkAvailability(t->position))){
				t->readMove();
			}

			// proper position was given so place mark on a board
			b->put(t->position, t->player->mark);

			endGame = checkEndGameConditions(b);
			if (endGame)
				break;

			// if it was x turn change turn to o and vice versa
			if (t->player->mark == 'x')
				t->player = player2;
			else
				t->player = player1;

			system("cls");
			b->draw();
		}

		if (checkPat(b))
			renderPat();
		else
			renderWinner(t->player);
	}
	else // player vs AI mode
	{
		while (1){
			t->readMove(); // write info on whos turn is right now and geather int from input

			// loop while user input bad position
			while (!(b->checkAvailability(t->position))){
				t->readMove();
			}

			// proper position was given so place mark on a board
			b->put(t->position, t->player->mark);

			endGame = checkEndGameConditions(b);
			if (endGame && !checkPat(b)){
				renderWinner(player1);
				break;
			}

			b->put(computerPlayer->pickPosition(b), computerPlayer->mark);
			endGame = checkEndGameConditions(b);
			if (endGame && !checkPat(b)){
				renderCompWinner();
				break;
			}

			system("cls");
			b->draw();
		}

		if (checkPat(b))
			renderPat();
	}
	

	std::cout << std::endl;
	system("pause");
	delete b;
	return 0;
}

