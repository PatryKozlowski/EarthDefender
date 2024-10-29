#pragma once

#include "Text.hpp"

class GameTimeBar
{
public:
	GameTimeBar();
	void Draw(sf::RenderWindow& window) const;
	void ShowTime(const unsigned int time);

private:
	std::unique_ptr<Text> m_Text;

	void InitTimeText() const;
};