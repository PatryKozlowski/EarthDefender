#include "ui/menu/EndGameScoreHUD.hpp"

EndGameScoreHUD::EndGameScoreHUD(ApplicationState& applicationState, Player& player)
	: m_ApplicationState{ applicationState },
	m_PlayerScore{ std::make_shared<Coin>() },
	m_PlayerHealth{ std::make_shared<Heart>() },
	m_PlayerTotalScore{ std::make_shared<Score>() },
	m_Player{ player }
{
	InitTitle();
	InitStatsElement();
	InitConfirmText();
}

void EndGameScoreHUD::Draw(sf::RenderWindow& window)
{
	DrawContainer(window);

	DrawTitle(window);

	DrawStats(window);

	DrawConfirmText(window);
}

void EndGameScoreHUD::HandleInput(const sf::Event& event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		if (m_Enter.GetBound().contains(event.mouseMove.x, event.mouseMove.y))
		{
			m_Enter.SetColor(MenuConfig::OPTION_HIGHLIGHT_COLOR);
		}
		else
		{
			m_Enter.SetColor(MenuConfig::OPTION_COLOR);
		}
	}

	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		if (m_Enter.GetBound().contains(event.mouseButton.x, event.mouseButton.y))
		{
			m_ApplicationState.SetCurrentState(GameStateID::END_GAME);
		}
	}
}


void EndGameScoreHUD::InitStatsElement()
{
	const unsigned int playerScore = m_Player.GetScore();
	m_PlayerScore.SetText(playerScore);
	m_PlayerScore.InitStatElement(StatElementID::SUMMARY_PLAYER_SCORE);


	const unsigned int playerHealth = m_Player.GetHealth();
	m_PlayerHealth.SetText(playerHealth);
	m_PlayerHealth.InitStatElement(StatElementID::SUMMARY_PLAYER_HEALTH);


	const unsigned int playerTotalScore = playerScore * playerHealth;
	m_PlayerTotalScore.SetText(playerTotalScore);
	m_PlayerTotalScore.InitStatElement(StatElementID::SUMMARY_PLAYER_TOTAL_SCORE);
}

void EndGameScoreHUD::InitTitle()
{
	m_Title.SetText(MenuConfig::TITLE_END_GAME_SCORE);

	m_Title.SetSize(MenuConfig::TITLE_SIZE);
	m_Title.SetPosition(sf::Vector2f(m_Container.GetContainerPosition().x + (m_Container.GetContainerGlobalBounds().width - m_Title.GetBound().width) / 2, 200.0f));
}

void EndGameScoreHUD::InitConfirmText()
{
	m_Enter.SetText(MenuConfig::CONFIRM);

	m_Enter.SetPosition(sf::Vector2f(m_Container.GetContainerPosition().x + (m_Container.GetContainerGlobalBounds().width - m_Enter.GetBound().width) / 2, 600.0f));
}

void EndGameScoreHUD::DrawStats(sf::RenderWindow& window)
{
	m_PlayerScore.Draw(window);

	m_PlayerHealth.Draw(window);

	m_PlayerTotalScore.Draw(window);
}

void EndGameScoreHUD::DrawTitle(sf::RenderWindow& window)
{
	m_Title.Draw(window);
}

void EndGameScoreHUD::DrawConfirmText(sf::RenderWindow& window)
{
	m_Enter.Draw(window);
}

void EndGameScoreHUD::DrawContainer(sf::RenderWindow& window)
{
	m_Container.Draw(window);
}
