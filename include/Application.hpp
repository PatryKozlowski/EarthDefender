#pragma once

#include <SFML/Graphics.hpp>
#include "ui/menu/MainMenuHUD.hpp"
#include "Game.hpp"
#include "ui/menu/EndGameHUD.hpp"

class Application
{
public:
	Application(unsigned int width, unsigned int height, const std::string &title, sf::Uint32 style);
	~Application() = default;

	void Run();

private:
	sf::RenderWindow m_Window;
	sf::Clock m_Clock;
	float m_TargetFps;
	GameStateID m_CurrentGameState;
	MainMenuHUD m_MainMenuHUD;
	EndGameHUD m_EndGameHUD;
	std::unique_ptr<Game> m_Game;

	void HandleGameStateInput(const sf::Event &event);
	void UpdateGameStates();
};
