#pragma once

#include "Object.hpp"

class Coin : public Object
{
public:
	Coin();
	void Draw(sf::RenderWindow& window) const override;
};