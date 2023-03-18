#include "ESymbol.h"

std::string SymbolToStr(const ESymbol& symbol)
{
	switch (symbol)
	{
	case ESymbol::None:
		return " ";
		break;
	case ESymbol::X:
		return "X";
		break;
	case ESymbol::O:
		return "O";
		break;
	}
}