#pragma once
#include "IGame.h"
#include "Player.h"
#include "Board.h"

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

	std::array <ESymbol, 9> GetBoardArray() const override;

	EGameState GetGameState() const override;

private:
	void UpdateGameState();

private:

	std::vector<IGameListener*> m_listeners;
	Board m_board;
	EGameState m_gameState;
	IPlayerPtr m_player1;
	IPlayerPtr m_player2;
	IPlayerPtr m_currentPlayer;
};

