#pragma once

#include "ui/menu/MenuHUD.hpp"

class MainMenuHUD : public MenuHUD
{
public:
	MainMenuHUD(sf::RenderWindow &window);

	void HandleInput(const sf::Event &event) override;
	bool IsStartGame() const;
	bool IsExitGame() const;

protected:
	void InitMainMenu();
	void DrawMenuTitle(sf::RenderWindow &window) override;
	void OnOptionClick(const std::string &label) override;

private:
	bool m_StartGame = false;
	bool m_ExitGame = false;
};