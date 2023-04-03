#pragma once
#include "IGameListener.h"
#include "IGame.h"

class ConsoleView : public IGameListener
{
public:
	ConsoleView(IGamePtr game);

	void RunGame();

private:
	int ChoosePosition(IPlayerPtr player);

	// IGameListener impl
	void OnMakeMove() override;
	void OnGameOver(IPlayerPtr player) override;

private:
	IGamePtr m_game;
	bool m_isComputerPlaying;
};

