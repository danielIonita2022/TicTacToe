#include "EBoardState.h"

EBoardState SymbolToState(ESymbol& symbol)
{
	if (symbol == ESymbol::X)
		return EBoardState::XWon;

	return EBoardState::OWon;
}