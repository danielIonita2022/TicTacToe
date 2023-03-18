#pragma once

#include "IPlayer.h"
#include "IBoard.h"

#include <memory>

using IGameListenerPtr = std::shared_ptr<class IGameListener>;
using IGameListenerWeakPtr = std::weak_ptr<class IGameListener>;

using IGamePtr = std::shared_ptr<class IGame>;

class IGameListener
{
public:

	virtual int OnPlayerTurn(IPlayerPtr player) = 0;
	virtual int OnInvalidMove() = 0;
	virtual void OnMakeMove() = 0;
	virtual void OnGameOver(IPlayerPtr player, bool isDraw) = 0;

	virtual ~IGameListener() = default;
};

