#pragma once
#include "Symbol.h"

enum class BoardState : uint8_t
{
	Ongoing,
	XWon,
	OWon,
	Draw
};

BoardState symbolToState(Symbol& symbol);

