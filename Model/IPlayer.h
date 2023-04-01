#pragma once
#include "ESymbol.h"

#include <memory>

using IPlayerPtr = std::shared_ptr<class IPlayer>;

class IPlayer
{
public:

	/// <summary>
	/// Method that sets the name of the player.
	/// </summary>
	/// <param name="name">The name that the player uses.</param>
	virtual void SetName(const std::string& name) = 0;
	/// <summary>
	/// Method that returns the name of the player.
	/// </summary>
	/// <returns>The name of the player.</returns>
	virtual std::string GetName() const = 0;
	/// <summary>
	/// Method that returns the symbol that the player uses.
	/// </summary>
	/// <returns>ESymbol::X, ESymbol::Y or ESymbol::None.</returns>
	virtual ESymbol GetSymbol() const = 0;
	/// <summary>
	/// Method that sets the symbol of the player.
	/// </summary>
	/// <param name="symbol">Enum class type that can be X or O</param>
	virtual void SetSymbol(ESymbol symbol) = 0;

	virtual ~IPlayer() = default;
};
