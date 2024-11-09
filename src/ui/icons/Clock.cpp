#include "ui/icons/Clock.hpp"

Clock::Clock()
	: Object(AssetSettings::CLOCK::TEXTURE_PATH, AssetSettings::CLOCK::SCALE, 0.0f, 0.0f)
{
}

void Clock::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
