#pragma once
#include "IPlayer.h"

class Player : public IPlayer
{
public:

	Player();
	Player(const std::string& playerName);
	Player(const Player& player);
	Player& operator=(const Player& player);

	std::string GetName() const override;
	void SetName(const std::string& name) override;

	ESymbol GetSymbol() const override;

	~Player();

private:

	static bool m_isFirstPlayer;
	std::string m_playerName;
	ESymbol m_playerSymbol;
};

