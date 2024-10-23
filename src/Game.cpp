#include "Game.hpp"
#include "GameConfig.hpp"

Game::Game(sf::RenderWindow &window)
    : m_Timer(g_GameConfig.GAME_TIME), m_GamePlayHUD(window)
{
}

void Game::StartGame(const float &deltaTime)
{
    m_GamePlayHUD.Draw();

    if (!m_Timer.IsActive())
    {
        m_Timer.Start();
    }

    const float leftTime = g_GameConfig.GAME_TIME - m_Timer.GetElapsedTime();

    m_GamePlayHUD.SetTime(leftTime);

    m_Timer.Update(deltaTime);

    if (m_Timer.IsExpired())
    {
        m_Timer.Stop();
        m_CurrentGameState = GameState::END_GAME;
    }
}

void Game::RestartGame()
{
    m_Timer.Reset();

    m_CurrentGameState = GameState::PLAYING;
}

GameState Game::GetCurrentGameState() const
{
    return m_CurrentGameState;
}