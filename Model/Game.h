#pragma once
#include "IGame.h"
#include "Board.h"
#include "Player.h"

#include <vector>

class Game : public IGame
{
public:

	Game();

	bool HasMadeMove(Player& player, int position) override;

	void CreatePlayer(int playerNo, const std::string& name) override;
	Player GetPlayer1() const override;
	Player GetPlayer2() const override;

	void AddListener(IGameListener* listener) override;
	void RemoveListener(IGameListener* listener) override;

	Board GetBoard() override;

	void UpdateGameState() override;
	EGameState GetGameState() const override;

private:

	std::vector<IGameListener*> m_listeners;
	Board m_board;
	EGameState m_gameState;
	Player m_player1;
	Player m_player2;
};

