#pragma once

#include "IPlayer.h"
#include "Board.h"

#include <memory>

using IGameListenerPtr = std::shared_ptr<class IGameListener>;
using IGameListenerWeakPtr = std::weak_ptr<class IGameListener>;

using IGamePtr = std::shared_ptr<class IGame>;

class IGameListener
{
public:
	/// <summary>
	/// Method that signals that the board has changed and updates the board with the new element.
	/// </summary>
	virtual void OnMakeMove(/*int x, int y*/) = 0;
	/// <summary>
	/// Method that signals that the game is over.
	/// </summary>
	/// <param name="player">The player that wins the game.</param>
	virtual void OnGameOver(IPlayerPtr player) = 0;

	virtual ~IGameListener() = default;
};

