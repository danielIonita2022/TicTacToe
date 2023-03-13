#pragma once
#include "IPlayer.h"
#include "IBoard.h"
#include <memory>

class IGameListener
{
public:
	virtual std::string OnEnterPlayer(bool isFirstPlayer) = 0;
	virtual int OnPlayerTurn(IPlayerPtr player) = 0;
	virtual int OnInvalidMove() = 0;
	virtual void OnMakeMove(const IBoardPtr board) = 0;
	virtual void OnGameOver(IPlayerPtr player) = 0;

	virtual ~IGameListener() = default;
};

using IGameListenerPtr = std::shared_ptr<IGameListener>;
using IGameListenerWeakPtr = std::weak_ptr<IGameListener>;