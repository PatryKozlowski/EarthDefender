#pragma once

#include "Object.hpp"

class Clock : public Object
{
public:
	Clock();
	void Draw(sf::RenderWindow& window) const override;
};
