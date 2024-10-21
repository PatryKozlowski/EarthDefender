#include "Application.hpp"

#include <iostream>

Application::Application(unsigned int width, unsigned int height, const std::string &title, sf::Uint32 style, float fps)
    : m_Window(sf::VideoMode(width, height), title, style), m_TargetFps(fps),
      m_CurrentGameState(GameState::MENU),
      m_MainMenuHUD(m_Window),
      m_GameOverHUD(m_Window),
      m_Game(g_GameConfig.GAME_TIME, m_Window)
{
}

void Application::Run()
{
    m_Clock.restart();
    float accumulatorTime = 0.0f;
    float timeStep = 1.0f / m_TargetFps;

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

            if (m_CurrentGameState == GameState::MENU)
            {
                m_MainMenuHUD.HandleInput(event);

                if (m_MainMenuHUD.IsStartGame())
                {
                    m_CurrentGameState = GameState::PLAYING;
                }

                else if (m_MainMenuHUD.IsExitGame())
                {
                    m_CurrentGameState = GameState::EXIT;
                    m_Window.close();
                }
            }
        }

        float frameDeltaTime = m_Clock.restart().asSeconds();
        accumulatorTime += frameDeltaTime;

        while (accumulatorTime >= timeStep)
        {
            accumulatorTime -= timeStep;

            m_Window.clear();

            if (m_CurrentGameState == GameState::GAME_OVER)
            {
                m_GameOverHUD.Draw();
                m_GameOverHUD.HandleInput(event);

                if (m_GameOverHUD.IsRestartGame())
                {
                    m_CurrentGameState = GameState::PLAYING;
                    m_Game.StartGame(timeStep);
                }

                else if (m_GameOverHUD.IsExitGame())
                {
                    m_CurrentGameState = GameState::EXIT;
                    m_Window.close();
                }
            }

            if (m_CurrentGameState == GameState::MENU)
            {
                m_MainMenuHUD.Draw();
            }

            else if (m_CurrentGameState == GameState::PLAYING)
            {
                m_Game.StartGame(timeStep);
                m_CurrentGameState = m_Game.GetCurrentGameState();
            }

            m_Window.display();
        }
    }
}