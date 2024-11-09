#pragma once

#include "Object.hpp"
#include "GameConfig.hpp"	

class ShieldBuff : public Object
{
public:
	ShieldBuff();
	void Draw(sf::RenderWindow& window) const override;
};