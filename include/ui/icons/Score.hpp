#pragma once

#include "Object.hpp"

class Score : public Object
{
public:
	Score();
	void Draw(sf::RenderWindow& window) const override;
};
