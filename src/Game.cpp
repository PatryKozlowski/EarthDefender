#include "Game.hpp"
#include "GameConfig.hpp"
#include "AssetManager.hpp"
#include <iostream>

Game::Game(sf::RenderWindow& window)
	: m_Window(window),
	m_GameTimer{ std::make_unique<Timer>(GameConfig::GAME_TIME) },
	m_MeteorsSpawnTimer{ std::make_unique<Timer>(GameConfig::METEOR_SPAWN_INTERVAL) },
	m_CurrentGameState{ GameState::PLAYING },
	m_GamePlayHUD{ std::make_unique<GamePlayHUD>(m_Window) },
	m_PlayerEarth{ std::make_unique<Earth>() },
	m_MeteorManager{ std::make_unique<MeteorManager>(m_Window) },
	m_PlayerHealth{ GameConfig::INIT_HEALTH },
	m_PlayerScore{ GameConfig::INIT_SCORE }
{
	AssetManager::GetInstance().LoadTexture(AssetSettings::METEOR::SMALL::TEXTURE_PATH);
	AssetManager::GetInstance().LoadTexture(AssetSettings::METEOR::MEDIUM::TEXTURE_PATH);
	AssetManager::GetInstance().LoadTexture(AssetSettings::METEOR::LARGE::TEXTURE_PATH);

	m_MeteorManager->SetMeteorTypes(AssetSettings::METEOR::METEOR_TYPES);
}

void Game::StartGame()
{
	DrawGameHUD();

	m_PlayerEarth->Draw(m_Window);

	StartTimers();

	UpdateMeteorSpawning();

	const bool isGameTimeExpired = m_GameTimer->IsExpired();

	if (isGameTimeExpired)
	{
		EndGame();
	}
	else if (m_PlayerHealth <= 0)
	{
		GameOver();
	}
}

void Game::RestartGame()
{
	m_GameTimer->Reset();
	m_MeteorsSpawnTimer->Reset();
	m_PlayerScore = GameConfig::INIT_SCORE;
	m_PlayerHealth = GameConfig::INIT_HEALTH;
	m_CurrentGameState = GameState::PLAYING;
}

void Game::HandleClick(sf::Vector2i& mousePosition)
{
	m_MeteorManager->HandleClick(mousePosition, m_PlayerScore);
}

GameState Game::GetCurrentGameState() const
{
	return m_CurrentGameState;
}

void Game::DrawGameHUD()
{
	m_GamePlayHUD->Update(m_PlayerHealth, m_PlayerScore, m_GameTimer->GetLeftTime());
	m_GamePlayHUD->Draw();
}

void Game::StartTimers()
{
	const bool isGameTimerRunning = m_GameTimer->IsActive();
	const bool isMeteorSpawnTimerRunning = m_MeteorsSpawnTimer->IsActive();

	if (!isGameTimerRunning)
	{
		m_GameTimer->Start();
	}

	if (!isMeteorSpawnTimerRunning)
	{
		m_MeteorsSpawnTimer->Start();
	}
}

void Game::Update(float deltaTime)
{
	m_MeteorManager->Update(deltaTime);
	m_MeteorsSpawnTimer->Update(deltaTime);
	m_GameTimer->Update(deltaTime);
}

void Game::UpdateMeteorSpawning()
{
	const bool isMeteorSpawnTimerExpired = m_MeteorsSpawnTimer->IsExpired();

	if (isMeteorSpawnTimerExpired)
	{
		m_MeteorManager->SpawnMeteor();
		m_MeteorsSpawnTimer->Reset();
	}

	m_MeteorManager->DrawMeteors(m_Window);

	m_MeteorManager->CheckCollisions(*m_PlayerEarth, m_PlayerHealth);
}

void Game::StopTimers()
{
	m_GameTimer->Stop();
	m_MeteorsSpawnTimer->Stop();
}

void Game::EndGame()
{
	StopTimers();
	m_MeteorManager->ClearMeteors();
	m_CurrentGameState = GameState::END_GAME;
}

void Game::GameOver()
{
	StopTimers();
	m_MeteorManager->ClearMeteors();
	//m_CurrentGameState = GameState::GAME_OVER;
	m_CurrentGameState = GameState::END_GAME;
}
