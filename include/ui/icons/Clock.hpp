#pragma once

#include "Object.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

class Clock : public Object
{
public:
	Clock();
	void Draw(sf::RenderWindow& window) const override;
};
