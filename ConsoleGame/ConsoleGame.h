#pragma once
#include <iostream>
#include "Player.h"
#include "Board.h"

class ConsoleGame
{
public:
	ConsoleGame();
	Player enterPlayer(const bool firstPlayer);
	void beginGame();
	void endGame();
	void printBoard();
	void printPlayerTurn(const Player& player);
	void printWinner(const Player& player);
	~ConsoleGame();
private:
	Player m_firstPlayer;
	Player m_secondPlayer;
	Board m_gameBoard;
};

