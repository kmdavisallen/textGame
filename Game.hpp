/**********************************************************************************
** Program Name: Final Project
** Author: Kevin Allen
** Date: 2/14/2018
** Description: This file contains the header for the game class
***********************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include "Linked.hpp"
#include <iostream>
#include <vector>

class Game {
private:
	Linked board;									//linked list to track spaces
	int starvationTimer = 20;						//timer for game
	int starveMultiplier = 1;						//ajusts timer is player is poisoned
	std::vector<int> backpack = { 0, 0, 0, 0, 0, 0 };	//backpack to contain food/idol
	int backpackIndex = 0;							//track number of items in backpack
	bool gameWin = false;
	bool gameLose = false;
public:
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void gameIntro();
	int moveMenu();
	void makeMove();
	int getStarveTimer();
	void eat();
	void interactRes();
	void state();
	bool getGameWin();
	bool getGameLose();

};
#endif