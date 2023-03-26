#pragma once
#include "IGameListener.h"
#include "IGame.h"

class ConsoleView : public IGameListener
{
public:

	ConsoleView(IGamePtr game);
	void StartGame();
	int ChoosePosition(Player player);
	void PlayerTurn(const Player& player);
	void OnMakeMove() override;
	void OnGameOver(Player& player) override;

private:

	IGamePtr m_game;
};

