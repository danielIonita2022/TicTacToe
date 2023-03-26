#pragma once
#include <string>
/// <summary>
/// This is an enum class that represents a symbol on the board.
/// </summary>
enum class ESymbol : uint8_t
{
	None, /// Blank space
	X, /// X Symbol
	O /// O Symbol
};

/// <summary>
/// Converts an ESymbol enum into an equivalent string.
/// </summary>
/// <param name="symbol">Enum Symbol value</param>
/// <returns>String converted from the enum</returns>
std::string SymbolToStr(const ESymbol& symbol);
