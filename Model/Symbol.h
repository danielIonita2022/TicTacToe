#pragma once
#include <string>

enum class Symbol
{
	None,
	X,
	O
};

std::string symbolToStr(const Symbol& symbol);
