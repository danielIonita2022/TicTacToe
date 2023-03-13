#include "BoardState.h"

BoardState SymbolToState(Symbol& symbol)
{
	if (symbol == Symbol::X)
		return BoardState::XWon;

	return BoardState::OWon;
}