#pragma once

#include "Object.hpp"

class Heart : public Object
{
public:
	Heart(float x, float y);
	void Draw(sf::RenderWindow& window) const override;
};
