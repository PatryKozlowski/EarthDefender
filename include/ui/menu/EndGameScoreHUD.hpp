#pragma once

#include "ApplicationState.hpp"
#include "Player.hpp"
#include "ui/menu/ContainerHUD.hpp"
#include "ui/StatElement.hpp"
#include "ui/icons/Coin.hpp"
#include "ui/icons/Score.hpp"
#include "ui/icons/Heart.hpp"
#include "GameConfig.hpp"

class EndGameScoreHUD
{
public:
	EndGameScoreHUD(ApplicationState& applicationState, Player& player);
	void Draw(sf::RenderWindow& window);
	void HandleInput(const sf::Event& event);

private:
	void InitStatsElement();
	void InitTitle();
	void InitConfirmText();
	void DrawStats(sf::RenderWindow& window);
	void DrawTitle(sf::RenderWindow& window);
	void DrawConfirmText(sf::RenderWindow& window);
	void DrawContainer(sf::RenderWindow& window);

	ApplicationState& m_ApplicationState;
	Player& m_Player;
	ContainerHUD m_Container;
	StatElement m_PlayerScore;
	StatElement m_PlayerHealth;
	StatElement m_PlayerTotalScore;
	Text m_Title;
	Text m_Enter;
};