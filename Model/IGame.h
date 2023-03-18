#pragma once

#include "IGameListener.h"
#include "IPlayer.h"
#include "IBoard.h"

class IGame
{
public:
	static IGamePtr Produce();

	virtual void StartGame() = 0;

	virtual IPlayerPtr DecideWinner() = 0;

	virtual void SetPlayerName(int playerNo, const std::string& name) = 0;

	virtual void MakeMove(const IPlayerPtr player) = 0;

	virtual void AddListener(const IGameListenerPtr listener) = 0;
	virtual void RemoveListener(const IGameListenerPtr listener) = 0;

	virtual IBoardPtr GetBoard() const = 0;
	virtual ~IGame() = default;
};

