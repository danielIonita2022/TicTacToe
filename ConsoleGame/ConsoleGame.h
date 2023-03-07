#pragma once
#include "IGame.h"
#include "Board.h"
#include "Player.h"

class ConsoleGame : public IGame
{
public:

	ConsoleGame() = default;
	void startScreen() override;
	~ConsoleGame();

private:

	void beginGame() override;
	void endGame() override;
	void printBoard() override;
	void printPlayerTurn(const IPlayerPtr& player) override;
	void printWinner(const IPlayerPtr& player) override;
	IPlayerPtr enterPlayer(const bool firstPlayer) override;

private:

	IPlayerPtr m_firstPlayer;
	IPlayerPtr m_secondPlayer;
	IBoardPtr m_gameBoard;
};

