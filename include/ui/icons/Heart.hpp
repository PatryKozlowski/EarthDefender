#pragma once

#include "Object.hpp"
#include "GameConfig.hpp"

class Heart : public Object
{
public:
	Heart();
	void Draw(sf::RenderWindow& window) const override;
};
