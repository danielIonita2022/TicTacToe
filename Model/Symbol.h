#pragma once
#include <string>

enum class Symbol : uint8_t
{
	None,
	X,
	O
};

std::string symbolToStr(const Symbol& symbol);
