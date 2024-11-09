#pragma once

#include "Object.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

class Score : public Object
{
public:
	Score();
	void Draw(sf::RenderWindow& window) const override;
};
