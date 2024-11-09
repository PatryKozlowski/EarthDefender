#pragma once

#include "Object.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

class Ufo : public Object
{
public:
	Ufo();
	void Draw(sf::RenderWindow& window) const;


private:
	float m_Radius;

};