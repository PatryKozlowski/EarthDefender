#include "ui/GameTimeBar.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

GameTimeBar::GameTimeBar() : m_Text{ std::make_unique<Text>() }
{
	//SetObjectPosition(WindowConfig::WIDTH / 2 - GetObjectBound().width / 2, AssetSettings::TIME_TEXT::Y_OFFSET);
}

void GameTimeBar::Draw(sf::RenderWindow& window) const
{

}

void GameTimeBar::ShowTime(const unsigned int time)
{
	m_Text->SetText(std::to_string(time));
}

void GameTimeBar::InitTimeText() const
{
	/*m_TimeText->SetSize(GamePlayHUDConfig::TEXT_SIZE);
	m_TimeText->SetColor(GamePlayHUDConfig::TEXT_COLOR);
	const float clockIconWidth = GetObjectBound().width;
	const float textYOffset = GetObjectPosition().y / 2;
	m_TimeText->SetPosition(sf::Vector2f(WindowConfig::WIDTH / 2 + clockIconWidth / 2 + 10, textYOffset));*/
}