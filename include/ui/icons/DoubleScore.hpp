#pragma once

#include "Object.hpp"

class DoubleScore : public Object
{
public:
	DoubleScore();
	void Draw(sf::RenderWindow& window) const override;
};