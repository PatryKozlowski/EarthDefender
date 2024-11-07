#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "ui/Text.hpp"
#include "ui/menu/ContainerHUD.hpp"
#include "GameConfig.hpp"
#include "ApplicationState.hpp"

class MenuHUD
{
public:
	MenuHUD(ApplicationState& applicationState);

	void Draw(sf::RenderWindow& window);
	void HandleInput(const sf::Event& event);

private:
	void InitOptions();
	void InitTitle();
	void DrawOptions(sf::RenderWindow& window);
	void DrawContainer(sf::RenderWindow& window);
	void DrawTitle(sf::RenderWindow& window);
	void HandleMouseMove(float x, float y);
	void HandleMouseClick(float x, float y);
	void OnOptionClick(const std::string& label);

	ApplicationState& m_ApplicationState;
	ContainerHUD m_Container;
	Text m_Text;
	std::vector<MenuOption> m_Options;
};