#include "Game.hpp"
#include "GameConfig.hpp"

Game::Game(sf::RenderWindow& window)
	: m_Window{ window },
	m_GameTimer{ std::make_unique<Timer>(GameConfig::GAME_TIME) },
	m_MeteorsSpawnTimer{ std::make_unique<Timer>(GameConfig::METEOR_SPAWN_INTERVAL) },
	m_CurrentGameState{ GameStateID::PLAYING },
	m_TopBarHUD{ std::make_unique<TopBarHUD>(m_Window) },
	m_PlayerEarth{ std::make_unique<Earth>() },
	m_MeteorManager{ std::make_unique<MeteorManager>(m_Window) },
	m_PlayerHealth{ GameConfig::INIT_HEALTH },
	m_PlayerScore{ GameConfig::INIT_SCORE }
{
}

void Game::StartGame()
{
	DrawTopBarHUD();

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
	m_CurrentGameState = GameStateID::PLAYING;
}

void Game::HandleClick(sf::Vector2i& mousePosition)
{
	m_MeteorManager->HandleClick(mousePosition, m_PlayerScore);
}

GameStateID Game::GetCurrentGameState() const
{
	return m_CurrentGameState;
}

void Game::DrawTopBarHUD()
{
	m_TopBarHUD->SetPlayerScore(m_PlayerScore);
	m_TopBarHUD->SetPlayerLife(m_PlayerHealth);
	m_TopBarHUD->SetGameTime(m_GameTimer->GetLeftTime());
	m_TopBarHUD->Draw();
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
	m_TopBarHUD->Update(deltaTime);
	m_GameTimer->Update(deltaTime);
}

void Game::UpdateMeteorSpawning()
{
	m_MeteorManager->SetMeteorTypes(AssetSettings::METEOR::METEOR_TYPES);

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
	m_CurrentGameState = GameStateID::END_GAME;
}

void Game::GameOver()
{
	StopTimers();
	m_MeteorManager->ClearMeteors();
	//m_CurrentGameState = GameState::GAME_OVER;
	m_CurrentGameState = GameStateID::END_GAME;
}
