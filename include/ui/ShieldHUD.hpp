#pragma once

#include <SFML/Graphics.hpp>
#include "ui/Shield.hpp"
#include "Earth.hpp"

class ShieldHUD
{
public:
	ShieldHUD(Earth& earth);

	void Draw(sf::RenderWindow& window) const;

private:
	std::unique_ptr<Shield> m_Shield;
	Earth& m_Earth;
};