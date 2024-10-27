#pragma once

#include "Object.hpp"
#include "Text.hpp"

class Coin : public Object
{
public:
	Coin();
	void Draw(sf::RenderWindow& window) const override;
	void ShowScore(const unsigned int score);

private:
	std::unique_ptr<Text> m_ScoreText;

	void InitCoin() const;
};