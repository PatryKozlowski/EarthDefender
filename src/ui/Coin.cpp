#include "ui/Coin.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

Coin::Coin()
	: Object(AssetSettings::COIN::TEXTURE_PATH, AssetSettings::COIN::SCALE, 0.0f, 0.0f),
	m_ScoreText{ std::make_unique<Text>() }
{
	SetObjectPosition(WindowConfig::WIDTH - GetObjectBound().width - 90.0f, AssetSettings::COIN::Y_OFFSET);

	InitCoin();
}

void Coin::Draw(sf::RenderWindow& window) const
{
	Object::Draw(window);

	if (m_ScoreText)
	{
		m_ScoreText->Draw(window);
	}
}

void Coin::ShowScore(const unsigned int score)
{
	m_ScoreText->SetText(std::to_string(score));
}

void Coin::InitCoin() const
{
	m_ScoreText->SetSize(GamePlayHUDConfig::TEXT_SIZE);
	m_ScoreText->SetColor(GamePlayHUDConfig::TEXT_COLOR);
	const float scoreIconWidth = GetObjectBound().width;
	const float textYOffset = GetObjectPosition().y / 2;
	m_ScoreText->SetPosition(sf::Vector2f(WindowConfig::WIDTH - scoreIconWidth / 2 - 65, textYOffset));
}