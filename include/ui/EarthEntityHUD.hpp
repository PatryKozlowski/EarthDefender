#pragma once

#include "ui/Earth.hpp"
#include "ui/ShieldHUD.hpp"
#include "Affect.hpp"
#include <SFML/Graphics.hpp>
#include <optional>

class EarthEntityHUD
{
public:
	EarthEntityHUD(Affect& affect);

	void Draw(sf::RenderWindow& window) const;
	void Update(float deltaTime);

	Earth& GetEarthEntity() { return m_Earth; }

private:
	Affect& m_Affect;
	std::optional<ShieldHUD> m_ShieldHUD;
	Earth m_Earth;
};