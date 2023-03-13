#pragma once
#include <string>

enum class Symbol : uint8_t
{
	None,
	X,
	O
};

std::string SymbolToStr(const Symbol& symbol);
