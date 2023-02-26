#pragma once
#include "Symbol.h"

enum class BoardState
{
	Ongoing,
	XWon,
	OWon,
	Draw
};

BoardState symbolToState(Symbol& symbol);

