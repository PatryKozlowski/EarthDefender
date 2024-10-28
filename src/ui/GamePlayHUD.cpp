#include "ui/GamePlayHUD.hpp"
#include "GameConfig.hpp"

GamePlayHUD::GamePlayHUD(sf::RenderWindow& window)
	: m_Window{ window }
{
}

void GamePlayHUD::SetGameTime(const float& time)
{
	m_GameTime.ShowTime(static_cast<unsigned int>(time));
}


void GamePlayHUD::SetPlayerScore(const unsigned int& score)
{
	m_Coin.ShowScore(score);
}

void GamePlayHUD::SetPlayerLives(const unsigned int& playerLives)
{
	m_Hearts.clear();

	for (unsigned int i = 0; i < playerLives; ++i)
	{
		Heart heart;
		heart.SetObjectPosition(AssetSettings::HEART::X_OFFSET + i * 40, 10);
		m_Hearts.emplace_back(heart);
	}
}

void GamePlayHUD::Update(const float deltaTime)
{
}

void GamePlayHUD::Draw() const
{
	sf::RectangleShape background(sf::Vector2f(WindowConfig::WIDTH, GamePlayHUDConfig::BACKGROUND_Y_OFFSET));

	background.setFillColor(GamePlayHUDConfig::BACKGROUND_COLOR);

	m_Window.draw(background);

	for (const auto& heart : m_Hearts)
	{
		heart.Draw(m_Window);
	}

	m_GameTime.Draw(m_Window);
	m_Coin.Draw(m_Window);
}