#include "Application.hpp"

Application::Application(const unsigned int width, const unsigned int height, const std::string &title, const sf::Uint32 style, const float fps)
    : m_Window(sf::VideoMode(width, height), title, style), m_TargetFps(fps),
      m_CurrentGameState(GameState::MENU),
      m_MainMenuHUD(m_Window),
      m_EndGameHUD(m_Window),
      m_Game(m_Window)
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

            HandleGameStateInput(event);
        }

        const float frameDeltaTime = m_Clock.restart().asSeconds();
        accumulatorTime += frameDeltaTime;

        while (accumulatorTime >= timeStep)
        {
            accumulatorTime -= timeStep;

            m_Window.clear();

            UpdateGameStates(timeStep);

            m_Window.display();
        }
    }
}

void Application::HandleGameStateInput(const sf::Event &event)
{
    switch (m_CurrentGameState)
    {
    case GameState::MENU:
        m_MainMenuHUD.HandleInput(event);

        if (m_MainMenuHUD.IsStartGame())
        {
            m_CurrentGameState = m_Game.GetCurrentGameState();
        }

        else if (m_MainMenuHUD.IsExitGame())
        {
            m_CurrentGameState = GameState::EXIT;
            m_Window.close();
        }
        break;

    case GameState::END_GAME:
        m_EndGameHUD.HandleInput(event);

        if (m_EndGameHUD.IsRestartGame())
        {
            m_Game.RestartGame();
            m_CurrentGameState = m_Game.GetCurrentGameState();
            m_EndGameHUD.ResetFlags();
        }
        else if (m_EndGameHUD.IsExitGame())
        {
            m_CurrentGameState = GameState::EXIT;
            m_Window.close();
        }
        break;

    default:
        break;
    }
}

void Application::UpdateGameStates(const float &deltaTime)
{
    switch (m_CurrentGameState)
    {
    case GameState::MENU:
        m_MainMenuHUD.Draw();
        break;

    case GameState::PLAYING:
        m_Game.StartGame(deltaTime);
        if (m_Game.GetCurrentGameState() == GameState::END_GAME)
        {
            m_CurrentGameState = GameState::END_GAME;
        }
        break;

    case GameState::END_GAME:
        m_EndGameHUD.Draw();
        break;

    default:
        break;
    }
}
