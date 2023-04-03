#pragma once
#include "IGame.h"
#include "Board.h"
#include "Player.h"
#include "IStrategy.h"
#include "EasyStrategy.h"
#include "MediumStrategy.h"
#include "HardStrategy.h"

#include <vector>

class Game : public IGame
{
public:

	Game();

	bool MakeMove(int position) override;

	void CreatePlayer(int playerNo, const std::string& name) override;
	IPlayerPtr GetPlayer1() const override;
	IPlayerPtr GetPlayer2() const override;
	IPlayerPtr GetCurrentPlayer() const override;

	void AddListener(IGameListener* listener) override;
	void RemoveListener(IGameListener* listener) override;

	std::array<ESymbol, 9> GetBoardArray() const override;

	EGameState GetGameState() const override;
	void SetStrategy(EGameDifficulty difficulty) override;
	void MakeComputerMove() override;
	
private:
	
	void UpdateGameState();

private:

	std::vector<IGameListener*> m_listeners;
	Board m_board;
	EGameState m_gameState;
	IPlayerPtr m_player1;
	IPlayerPtr m_player2;
	IPlayerPtr m_currentPlayer;
	IStrategyPtr m_strategy;
};

