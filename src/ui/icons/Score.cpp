#include "ui/icons/Score.hpp"

Score::Score()
	: Object(AssetSettings::SCORE::TEXTURE_PATH, AssetSettings::SCORE::SCALE, 0.0f, 0.0f)
{
}

void Score::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
