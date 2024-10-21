#include "Application.hpp"

#include <iostream>

Application::Application(unsigned int width, unsigned int height, const std::string &title, sf::Uint32 style, float fps)
    : m_Window(sf::VideoMode(width, height), title, style), m_TargetFps(fps), m_CurrentGameState(GameState::MENU)
{
    m_Menu = std::make_unique<Menu>(m_Window);
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
                bool startGame = false;
                bool exitGame = false;

                m_Menu->HandleInput(event, startGame, exitGame);

                if (startGame)
                {
                    m_CurrentGameState = GameState::PLAYING;
                }

                else if (exitGame)
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

            if (m_CurrentGameState == GameState::MENU)
            {
                m_Menu->Draw();
            }

            else if (m_CurrentGameState == GameState::PLAYING)
            {
                std::cout << "Playing game" << std::endl;
            }

            m_Window.display();
        }
    }
}