#pragma once

#include "Object.hpp"

class Heart : public Object
{
public:
	Heart();
	void Draw(sf::RenderWindow& window) const override;
};
