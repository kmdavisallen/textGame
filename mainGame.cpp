/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 2/14/2018
** Description: This file contains the main implmentation for the final project
***********************************************************************************/
#include "Game.hpp"
#include <time.h>

int main() {
	
	
	srand(time(NULL));

	do {
		Game gameOne;
		gameOne.gameIntro();
		while (gameOne.getGameWin() == false && gameOne.getGameLose() == false) {
			gameOne.makeMove();
			gameOne.interactRes();
			gameOne.state();			
		}
	
	} while (playAgainMenu() == 1);

	return 0;
}