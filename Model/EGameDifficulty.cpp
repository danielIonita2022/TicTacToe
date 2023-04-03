#include "EGameDifficulty.h"
#include <string>

EGameDifficulty StrToDifficulty(const std::string& str)
{
	if (str == "Easy")
		return EGameDifficulty::Easy;
	else if (str == "Medium")
		return EGameDifficulty::Medium;
	else if (str == "Hard")
		return EGameDifficulty::Hard;
}