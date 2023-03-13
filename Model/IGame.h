#pragma once
#include "IGameListener.h"
#include "IPlayer.h"
#include "IBoard.h"

using IGamePtr = std::shared_ptr<class IGame>;

class IGame
{
public:
	static IGamePtr Produce();
	virtual void StartGame() = 0;
	virtual IPlayerPtr BeginGameLoop() = 0;
	virtual void MakeMove(const IPlayerPtr player) = 0;
	virtual void EndGame() = 0;
	virtual void AddListener(IGameListenerPtr listener) = 0;
	virtual void RemoveListener(IGameListenerPtr listener) = 0;
	virtual IBoardPtr GetBoard() const = 0;
	virtual ~IGame() = default;
};

