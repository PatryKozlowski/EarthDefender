#include "ui/icons/Coin.hpp"

Coin::Coin()
	: Object(AssetSettings::COIN::TEXTURE_PATH, AssetSettings::COIN::SCALE, 0.0f, 0.0f)
{
}

void Coin::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
