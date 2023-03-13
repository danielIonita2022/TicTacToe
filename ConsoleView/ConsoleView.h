#pragma once
#include "IGameListener.h"
#include "IGame.h"

class ConsoleView : public IGameListener
{
public:
	ConsoleView(IGamePtr game);
	std::string OnEnterPlayer(bool isFirstPlayer) override;
	int OnPlayerTurn(IPlayerPtr player) override;
	int OnInvalidMove() override;
	void OnMakeMove(const IBoardPtr board) override;
	void OnGameOver(IPlayerPtr player) override;

private:
	IGamePtr m_game;
};

