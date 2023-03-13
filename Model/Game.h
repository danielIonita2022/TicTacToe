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
	IPlayerPtr BeginGameLoop() override;
	void MakeMove(const IPlayerPtr player) override;
	void EndGame() override;
	void AddListener(IGameListenerPtr listener) override;
	void RemoveListener(IGameListenerPtr listener) override;
	IBoardPtr GetBoard() const override;

private:
	std::vector<IGameListenerWeakPtr> m_listeners;
	IBoardPtr m_board;
	IPlayerPtr m_player1;
	IPlayerPtr m_player2;
	bool m_isOver;

};

