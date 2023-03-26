#include "EGameState.h"

EGameState SymbolToState(ESymbol& symbol)
{
	if (symbol == ESymbol::X)
		return EGameState::XWon;

	return EGameState::OWon;
}