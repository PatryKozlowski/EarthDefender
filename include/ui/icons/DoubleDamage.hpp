#pragma once

#include "Object.hpp"

class DoubleDamage : public Object
{
public:
	DoubleDamage();
	void Draw(sf::RenderWindow& window) const override;
};