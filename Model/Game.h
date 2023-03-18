#pragma once
#include "IGame.h"
#include "IBoard.h"
#include "IPlayer.h"

#include <vector>

class Game : public IGame
{
public:

	Game();
	
	void StartGame() override;

	IPlayerPtr DecideWinner() override;

	void MakeMove(const IPlayerPtr player) override;

	void SetPlayerName(int playerNo, const std::string& name) override;

	void AddListener(const IGameListenerPtr listener) override;
	void RemoveListener(const IGameListenerPtr listener) override;

	IBoardPtr GetBoard() const override;

private:

	std::vector<IGameListenerWeakPtr> m_listeners;
	IBoardPtr m_board;
	IPlayerPtr m_player1;
	IPlayerPtr m_player2;
	bool m_isOver;
	bool m_isDraw;
};

