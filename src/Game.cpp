#include "Game.hpp"
#include "GameConfig.hpp"

Game::Game(sf::RenderWindow& window)
	: m_Window{ window },
	m_GameTimer{ std::make_unique<Timer>(GameConfig::GAME_TIME) },
	m_MeteorsSpawnTimer{ std::make_unique<Timer>(GameConfig::METEOR_SPAWN_INTERVAL) },
	m_BuffsSpawnTimer{ std::make_unique<Timer>(AssetSettings::BUFF::SPAWN_INTERVAL) },
	m_CurrentGameState{ GameStateID::PLAYING },
	m_TopBarHUD{ std::make_unique<TopBarHUD>(m_Window) },
	m_Player{ std::make_unique<Player>() },
	m_MeteorManager{ std::make_unique<MeteorManager>(m_Window, *m_Player) },
	m_BuffManager{ std::make_unique<BuffManager>(m_Window, *m_Player) }
{
}

void Game::StartGame()
{
	DrawTopBarHUD();

	m_Player->SpawnPlayer(m_Window);

	StartTimers();

	UpdateMeteorSpawning();

	UpdateBuffSpawning();

	if (m_GameTimer->IsExpired())
	{
		EndGame();
	}
	else if (m_Player->GetHealth() <= 0)
	{
		GameOver();
	}
}

void Game::RestartGame()
{
	m_GameTimer->Reset();
	m_MeteorsSpawnTimer->Reset();
	m_Player->SetScore(GameConfig::INIT_SCORE);
	m_Player->SetHealth(GameConfig::INIT_HEALTH);
	m_CurrentGameState = GameStateID::PLAYING;
}

void Game::HandleClick(sf::Vector2i& mousePosition)
{
	m_MeteorManager->HandleClick(mousePosition);
	m_BuffManager->HandleClick(mousePosition);
}

GameStateID Game::GetCurrentGameState() const
{
	return m_CurrentGameState;
}

void Game::DrawTopBarHUD()
{
	m_TopBarHUD->SetPlayerScore(m_Player->GetScore());
	m_TopBarHUD->SetPlayerLife(m_Player->GetHealth());
	m_TopBarHUD->SetGameTime(m_GameTimer->GetLeftTime());
	m_TopBarHUD->SetBuffSlot(m_Player->GetActiveBuff());
	m_TopBarHUD->Draw();
}

void Game::StartTimers()
{
	if (!m_GameTimer->IsActive())
	{
		m_GameTimer->Start();
	}

	if (!m_MeteorsSpawnTimer->IsActive())
	{
		m_MeteorsSpawnTimer->Start();
	}

	if (!m_BuffsSpawnTimer->IsActive())
	{
		m_BuffsSpawnTimer->Start();
	}
}

void Game::Update(float deltaTime)
{
	m_MeteorManager->Update(deltaTime);
	m_MeteorsSpawnTimer->Update(deltaTime);
	m_TopBarHUD->Update(deltaTime);
	m_GameTimer->Update(deltaTime);
	m_BuffManager->Update(deltaTime);
	m_BuffsSpawnTimer->Update(deltaTime);
}

void Game::UpdateMeteorSpawning()
{
	m_MeteorManager->SetMeteorTypes(AssetSettings::METEOR::METEOR_TYPES);

	if (m_MeteorsSpawnTimer->IsExpired())
	{
		m_MeteorManager->SpawnMeteor();
		m_MeteorsSpawnTimer->Reset();
	}

	m_MeteorManager->DrawMeteors(m_Window);

	m_MeteorManager->CheckCollisions();
}

void Game::UpdateBuffSpawning()
{
	m_BuffManager->SetBuffTypes(AssetSettings::BUFF::BUFF_TYPES);

	if (m_BuffsSpawnTimer->IsExpired())
	{
		m_BuffManager->SpawnBuff();
		m_BuffsSpawnTimer->Reset();
	}

	m_BuffManager->DrawBuffs(m_Window);
}

void Game::ResetSpowners()
{
	m_MeteorsSpawnTimer->Reset();
	m_BuffsSpawnTimer->Reset();

	m_MeteorManager->ClearMeteors();
	m_BuffManager->ClearBuffs();
}

void Game::StopTimers()
{
	m_GameTimer->Stop();
	m_MeteorsSpawnTimer->Stop();
	m_BuffsSpawnTimer->Stop();
}

void Game::EndGame()
{
	StopTimers();
	ResetSpowners();
	m_CurrentGameState = GameStateID::END_GAME;
}

void Game::GameOver()
{
	StopTimers();
	ResetSpowners();
	//m_CurrentGameState = GameState::GAME_OVER;
	m_CurrentGameState = GameStateID::END_GAME;
}