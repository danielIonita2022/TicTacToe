#pragma once
#include <string>
#include "Symbol.h"

class Player
{
public:
	Player();
	Player(const std::string& playerName);
	Player(const Player& player);
	Player& operator=(const Player& player);
	~Player();
	std::string getName() const;
	Symbol getSymbol() const;
	void setName(const std::string& name);

private:
	static bool m_isFirstPlayer;
	std::string m_playerName;
	Symbol m_playerSymbol;
};

