#include "ui/icons/ShieldBuff.hpp"

#include "GameConfig.hpp"	

ShieldBuff::ShieldBuff()
	:Object(AssetSettings::BUFF::INVINCIBILITY::TEXTURE_PATH, AssetSettings::BUFF::SCALE, 0.0f, 0.0f)
{
}

void ShieldBuff::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);
}
