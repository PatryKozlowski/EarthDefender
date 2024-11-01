#include "ui/Shield.hpp"

#include "GameConfig.hpp"	

Shield::Shield()
	:Object(AssetSettings::SHIELD::TEXTURE_PATH, AssetSettings::SHIELD::SCALE, 0.0f, 0.0f)
{
}

void Shield::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
