#pragma once
#include <string>
enum class EGameDifficulty
{
	Easy,
	Medium,
	Hard
};

EGameDifficulty StrToDifficulty(const std::string& str);