#include "BoardState.h"

BoardState symbolToState(Symbol& symbol)
{
	if (symbol == Symbol::X)
		return BoardState::XWon;

	return BoardState::OWon;
}