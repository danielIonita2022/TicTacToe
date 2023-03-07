#pragma once
#include <memory>
#include <string>
#include "Symbol.h"

using IPlayerPtr = std::shared_ptr<class IPlayer>;

class IPlayer
{
public:

	static IPlayerPtr Produce(const std::string& playerName);
	virtual void setName(const std::string& name) = 0;
	virtual std::string getName() const = 0;
	virtual Symbol getSymbol() const = 0;
	virtual ~IPlayer() = default;
};
