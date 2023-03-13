#pragma once
#include <memory>
#include <string>
#include "Symbol.h"

using IPlayerPtr = std::shared_ptr<class IPlayer>;

class IPlayer
{
public:

	static IPlayerPtr Produce(const std::string& playerName);
	virtual void SetName(const std::string& name) = 0;
	virtual std::string GetName() const = 0;
	virtual Symbol GetSymbol() const = 0;
	virtual ~IPlayer() = default;
};
