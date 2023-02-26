#include "Symbol.h"

std::string symbolToStr(const Symbol& symbol)
{
	switch (symbol)
	{
	case Symbol::None:
		return " ";
		break;
	case Symbol::X:
		return "X";
		break;
	case Symbol::O:
		return "O";
		break;
	}
}