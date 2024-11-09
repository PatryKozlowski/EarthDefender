#pragma once

#include "Object.hpp"
#include "GameConfig.hpp"

class Shield : public Object
{
public:
	Shield();
	void Draw(sf::RenderWindow& window) const override;
};