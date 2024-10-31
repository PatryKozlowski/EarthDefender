#pragma once

#include "Object.hpp"

class SlowClock : public Object
{
public:
	SlowClock();
	void Draw(sf::RenderWindow& window) const override;
};
