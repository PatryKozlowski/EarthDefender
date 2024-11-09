#pragma once

#include "Object.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

class Coin : public Object
{
public:
	Coin();
	void Draw(sf::RenderWindow& window) const override;
};