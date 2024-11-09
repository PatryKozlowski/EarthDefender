#pragma once

#include "Object.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

class SlowClock : public Object
{
public:
	SlowClock();
	void Draw(sf::RenderWindow& window) const override;
};
