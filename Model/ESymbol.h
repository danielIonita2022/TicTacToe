#pragma once
#include <string>

enum class ESymbol : uint8_t
{
	None,
	X,
	O
};

std::string SymbolToStr(const ESymbol& symbol);
