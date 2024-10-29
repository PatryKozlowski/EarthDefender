#include "ui/bars/PlayerScoreBar.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

PlayerScoreBar::PlayerScoreBar() : m_Text{std::make_unique<Text>()},
								   m_Coin{std::make_unique<Coin>()}
{
}

void PlayerScoreBar::Draw(sf::RenderWindow &window) const
{
	m_Coin->Draw(window);
	m_Text->Draw(window);
}

void PlayerScoreBar::ShowTime(const unsigned int time) const
{
	m_Text->SetText(std::to_string(time));
}

void PlayerScoreBar::InitGamePlayerScoreBar()
{
	const auto clockIconWidth = m_Coin->GetObjectBound().width;
	const auto textYOffset = m_Coin->GetObjectPosition().y + 5.0f;

	m_Coin->SetObjectPosition(WindowConfig::WIDTH / 2 - clockIconWidth / 2, AssetSettings::CLOCK::Y_OFFSET);

	m_Text->SetSize(GamePlayHUDConfig::TEXT_SIZE);
	m_Text->SetColor(GamePlayHUDConfig::TEXT_COLOR);

	m_Text->SetPosition(sf::Vector2f(WindowConfig::WIDTH / 2 + clockIconWidth / 2 + 10, textYOffset));
}