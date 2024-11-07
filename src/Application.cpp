#include "Application.hpp"
#include "AssetManager.hpp"

Application::Application(const unsigned int width, const unsigned int height, const std::string& title, const sf::Uint32 style)
	: m_Window{ sf::VideoMode(width, height), title, style },
	m_TargetFps{ WindowConfig::TARGET_FPS },
	m_ApplicationState{ GameStateID::MENU },
	m_Game{ m_Window, m_ApplicationState }
{
}

void Application::Run()
{
	m_Clock.restart();
	float accumulatorTime = 0.0f;
	const float timeStep = 1.0f / m_TargetFps;

	m_Window.setFramerateLimit(static_cast<unsigned int>(m_TargetFps));

	while (m_Window.isOpen())
	{
		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				m_Window.close();
			}

			HandleEvent(event);

		}

		const float frameDeltaTime = m_Clock.restart().asSeconds();
		accumulatorTime += frameDeltaTime;

		while (accumulatorTime >= timeStep)
		{
			accumulatorTime -= timeStep;

			m_Window.clear();

			UpdateGameStates();

			m_Game.Update(timeStep);

			m_Window.display();
		}
	}
}

void Application::HandleEvent(const sf::Event& event)
{
	if (m_Menu)
	{
		m_Menu->HandleInput(event);
	}

	m_Game.HandleInput(event);
}

void Application::UpdateGameStates()
{
	switch (m_ApplicationState.GetCurrentState())
	{
	case GameStateID::MENU:
	case GameStateID::END_GAME:
	case GameStateID::GAME_OVER:
		if (!m_Menu)
		{
			m_Menu = std::make_unique<MenuHUD>(m_ApplicationState);
		}
		m_Menu->Draw(m_Window);
		break;

	case GameStateID::PLAYING:
		m_Game.StartGame();
		m_Menu.reset();
		break;

	case GameStateID::RESTART:
		m_Game.RestartGame();
		break;

	case GameStateID::END_GAME_SCORE:
		m_Game.ShowScoreBoard();
		break;

	case GameStateID::EXIT:
		m_Window.close();
		break;

	default:
		break;
	}
}
