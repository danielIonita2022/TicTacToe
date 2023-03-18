#pragma once
#include "IGameListener.h"
#include "IGame.h"

class ConsoleView : public IGameListener
{
public:

	ConsoleView(IGamePtr game);

	int OnPlayerTurn(IPlayerPtr player) override;
	int OnInvalidMove() override;
	void OnMakeMove() override;
	void OnGameOver(IPlayerPtr player, bool isDraw) override;

private:

	IGamePtr m_game;
};

