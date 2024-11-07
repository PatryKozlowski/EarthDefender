#include "ui/bars/TopBarHUD.hpp"
#include "GameConfig.hpp"

TopBarHUD::TopBarHUD(sf::RenderWindow& window)
	: m_Window{ window },
	m_BuffSlotBar{ std::make_unique<BuffSlotBar>() }
{
	InitTopBarHUD();
}

void TopBarHUD::SetGameTime(const float& time) const
{
	const auto timeToShow = static_cast<unsigned int>(time);
	m_GameTimeBar.SetText(timeToShow);
}

void TopBarHUD::SetPlayerScore(const unsigned int& score)
{
	m_PlayerScoreBar.SetText(score);
}

void TopBarHUD::SetPlayerLife(const unsigned int& playerLife)
{
	m_PlayerLivesBar.SetLife(playerLife);
}

void TopBarHUD::SetBuffSlot(const BuffTypeID& buffType) const
{
	m_BuffSlotBar->SetBuffSlot(buffType);
}

void TopBarHUD::InitTopBarHUD()
{
	m_GameTimeBar.InitStatElement(StatElementID::GAME_TIME_BAR);
	m_PlayerScoreBar.InitStatElement(StatElementID::PLAYER_SCORE_BAR);
}

void TopBarHUD::Update(const float deltaTime)
{
	m_PlayerLivesBar.Update(deltaTime);
	m_GameTimeBar.Update(deltaTime);
}

void TopBarHUD::Draw() const
{
	sf::RectangleShape background(sf::Vector2f(WindowConfig::WIDTH, TopBarHUDConfig::BACKGROUND_Y_OFFSET));

	background.setFillColor(TopBarHUDConfig::BACKGROUND_COLOR);

	m_Window.draw(background);

	m_PlayerLivesBar.Draw(m_Window);
	m_GameTimeBar.Draw(m_Window);
	m_PlayerScoreBar.Draw(m_Window);
	m_BuffSlotBar->Draw(m_Window);
}