#include "ui/MainMenuHUD.hpp"
#include "GameConfig.hpp"

MainMenuHUD::MainMenuHUD(sf::RenderWindow& window)
	: MenuHUD{ window }
{
	InitMainMenu();
}

void MainMenuHUD::HandleInput(const sf::Event& event)
{
	MenuHUD::HandleInput(event);
}

bool MainMenuHUD::IsStartGame() const
{
	return m_StartGame;
}

bool MainMenuHUD::IsExitGame() const
{
	return m_ExitGame;
}

void MainMenuHUD::InitMainMenu()
{
	InitOptions({ MenuConfig::START_GAME, MenuConfig::EXIT });
}

void MainMenuHUD::DrawMenuTitle(sf::RenderWindow& window)
{
	MenuHUD::DrawMenuTitle(window);
}

void MainMenuHUD::OnOptionClick(const std::string& label)
{
	if (label == MenuConfig::START_GAME)
	{
		m_StartGame = true;
	}

	if (label == MenuConfig::EXIT)
	{
		m_ExitGame = true;
	}
}
