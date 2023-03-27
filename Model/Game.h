#pragma once
#include "IGame.h"
#include "Board.h"
#include "Player.h"

#include <vector>

class Game : public IGame
{
public:

	Game();

	bool HasMadeMove(IPlayerPtr& player, int position) override;

	void CreatePlayer(int playerNo, const std::string& name) override;
	IPlayerPtr GetPlayer1() const override;
	IPlayerPtr GetPlayer2() const override;

	void AddListener(IGameListener* listener) override;
	void RemoveListener(IGameListener* listener) override;

	Board GetBoard() override;

	void UpdateGameState() override;
	EGameState GetGameState() const override;

private:

	std::vector<IGameListener*> m_listeners;
	Board m_board;
	EGameState m_gameState;
	IPlayerPtr m_player1;
	IPlayerPtr m_player2;
};

