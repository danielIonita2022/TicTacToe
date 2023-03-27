#pragma once
#include "IGameListener.h"
#include "IGame.h"

class ConsoleView : public IGameListener
{
public:

	ConsoleView(IGamePtr game);
	void StartGame();
	int ChoosePosition(IPlayerPtr& player);
	void PlayerTurn(IPlayerPtr& player);
	void OnMakeMove() override;
	void OnGameOver(IPlayerPtr& player) override;

private:

	IGamePtr m_game;
};

