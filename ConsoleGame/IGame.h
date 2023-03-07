#pragma once
#include <memory>
#include "IPlayer.h"

enum class EGameType : uint8_t
{
	Impl1,
	Impl2
};

/* forward declaration: ii promite ca va gasi mai jos IGame*/
using IGamePtr = std::shared_ptr<class IGame>;

class IGame
{
public:

	static IGamePtr Produce(EGameType type);
	virtual void startScreen() = 0;
	virtual ~IGame() = default;

protected:

	virtual void beginGame() = 0;
	virtual void endGame() = 0;
	virtual void printBoard() = 0;
	virtual void printPlayerTurn(const IPlayerPtr& player) = 0;
	virtual void printWinner(const IPlayerPtr& player) = 0;
	virtual IPlayerPtr enterPlayer(const bool firstPlayer) = 0;

};
