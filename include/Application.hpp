#pragma once

#include <SFML/Graphics.hpp>
#include "ui/menu/MenuHUD.hpp"
#include "Game.hpp"
#include "ApplicationState.hpp"
#include "AssetManager.hpp"

class Application
{
public:
	Application(unsigned int width, unsigned int height, const std::string& title, sf::Uint32 style);
	~Application() = default;

	void Run();

private:
	sf::RenderWindow m_Window;
	sf::Clock m_Clock;
	float m_TargetFps;
	ApplicationState m_ApplicationState;
	std::unique_ptr<MenuHUD> m_Menu;
	Game m_Game;

	void HandleEvent(const sf::Event& event);
	void UpdateGameStates();
};
