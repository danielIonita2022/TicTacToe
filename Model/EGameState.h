#pragma once
#include "ESymbol.h"
/** EGameState represents the state of the game board. */
enum class EGameState : uint8_t
{
	/// Represents an ongoing game.
	Ongoing, 
	/// The game was won by the X Player.
	XWon, 
	/// The game was won by the O Player.
	OWon, 
	/// The game was a draw.
	Draw 
};

/// <summary>
/// Converts an ESymbol enum into an equivalent EGameState enum.
/// </summary>
/// <param name="symbol">ESymbol enum value</param>
/// <returns>EGameState enum value</returns>
EGameState SymbolToState(ESymbol& symbol);