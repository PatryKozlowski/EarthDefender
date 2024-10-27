#include "ui/GameTime.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

GameTime::GameTime() :
	Object(AssetSettings::TIME_TEXT::TEXTURE_PATH, AssetSettings::TIME_TEXT::SCALE, 0.0f, 0.0f),
	m_TimeText{ std::make_unique<Text>() }
{
	SetObjectPosition(WindowConfig::WIDTH / 2 - GetObjectBound().width / 2, AssetSettings::TIME_TEXT::Y_OFFSET);

	InitTimeText();
}

void GameTime::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);

	if (m_TimeText)
	{
		m_TimeText->Draw(window);
	}
}

void GameTime::ShowTime(const unsigned int time)
{
	m_TimeText->SetText(std::to_string(time));
}

void GameTime::InitTimeText() const
{
	m_TimeText->SetSize(GamePlayHUDConfig::TEXT_SIZE);
	m_TimeText->SetColor(GamePlayHUDConfig::TEXT_COLOR);
	const float clockIconWidth = GetObjectBound().width;
	const float textYOffset = GetObjectPosition().y / 2;
	m_TimeText->SetPosition(sf::Vector2f(WindowConfig::WIDTH / 2 + clockIconWidth / 2 + 10, textYOffset));
}