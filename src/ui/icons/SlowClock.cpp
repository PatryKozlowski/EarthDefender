#include "ui/icons/SlowClock.hpp"

SlowClock::SlowClock()
	: Object(AssetSettings::BUFF::SLOW_METEOR_SPEED::TEXTURE_PATH, AssetSettings::SLOW_CLOCK::SCALE, 0.0f, 0.0f)
{
}

void SlowClock::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
