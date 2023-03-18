#pragma once
#include "ESymbol.h"

enum class EBoardState : uint8_t
{
	Ongoing,
	XWon,
	OWon,
	Draw
};

EBoardState SymbolToState(ESymbol& symbol);

