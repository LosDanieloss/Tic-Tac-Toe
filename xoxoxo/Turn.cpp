#include "stdafx.h"
#include "Turn.h"
#include <iostream>


Turn::Turn()
{
	position = -1;
}


Turn::~Turn()
{
}

void Turn::readMove(){
	renderTurnInfo();
	std::cin >> position;
	position -= 1;

	while (position < 0 && position > 8){
		renderTurnInfo();
		std::cin >> position;
		position -= 1;
	}
}

void Turn::renderTurnInfo(){
	std::cout << player->name << " turn, so press number from 1 to 9 where to put mark " << player->mark << std::endl;
}