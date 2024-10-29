#include "ui/menu/EndGameHUD.hpp"
#include "GameConfig.hpp"

EndGameHUD::EndGameHUD(sf::RenderWindow &window)
	: MenuHUD(window)
{
	InitEndGameHUD();
}

void EndGameHUD::HandleInput(const sf::Event &event)
{
	MenuHUD::HandleInput(event);
}

bool EndGameHUD::IsRestartGame() const
{
	return m_RestartGame;
}

bool EndGameHUD::IsExitGame() const
{
	return m_ExitGame;
}

void EndGameHUD::ResetFlags()
{
	m_RestartGame = false;
	m_ExitGame = false;
}
void EndGameHUD::InitEndGameHUD()
{
	InitOptions({MenuConfig::PLAY_AGAIN, MenuConfig::EXIT});
}

void EndGameHUD::DrawMenuTitle(sf::RenderWindow &window)
{
	m_Title->SetText(MenuConfig::TITLE_END_GAME);
	m_Title->SetSize(MenuConfig::TITLE_SIZE);
	m_Title->SetColor(MenuConfig::TITLE_COLOR);
	m_Title->SetPosition(sf::Vector2f(window.getSize().x / 2 - m_Title->GetBound().width / 2, MenuConfig::TITLE_Y));
	m_Title->Draw(window);
}

void EndGameHUD::OnOptionClick(const std::string &label)
{
	if (label == MenuConfig::PLAY_AGAIN)
	{
		m_RestartGame = true;
	}

	if (label == MenuConfig::EXIT)
	{
		m_ExitGame = true;
	}
}