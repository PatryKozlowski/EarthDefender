#pragma once

#include "Object.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

class Earth : public Object
{
public:
	Earth();
	void Draw(sf::RenderWindow& window) const;


private:
	float m_Radius;

};