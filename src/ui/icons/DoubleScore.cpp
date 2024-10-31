#include "ui/icons/DoubleScore.hpp"

#include "GameConfig.hpp"	

DoubleScore::DoubleScore()
	:Object(AssetSettings::BUFF::DOUBLE_SCORE::TEXTURE_PATH, AssetSettings::BUFF::SCALE, 0.0f, 0.0f)
{
}

void DoubleScore::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
