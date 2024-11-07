#include "Game.hpp"
#include "GameConfig.hpp"
#include "Meteor.hpp"

Game::Game(sf::RenderWindow& window, ApplicationState& applicationState)
	: m_Window{ window },
	m_GameTimer{ GameConfig::GAME_TIME },
	m_MeteorsSpawnTimer{ GameConfig::METEOR_SPAWN_INTERVAL },
	m_BuffsSpawnTimer{ GameConfig::SPAWN_INTERVAL },
	m_TopBarHUD{ m_Window },
	m_Affect{},
	m_Player{ m_Affect },
	m_EarthEntityHUD{ m_Affect },
	m_MeteorManager{ m_Window, m_Player, m_Affect, m_EarthEntityHUD },
	m_BuffManager{ m_Window, m_Player ,m_Affect },
	m_ApplicationState{ applicationState }
{
}

void Game::StartGame()
{
	if (m_EndGameScore)
	{
		m_EndGameScore.reset();
	}

	m_ApplicationState.SetCurrentState(GameStateID::PLAYING);

	DrawTopBarHUD();

	DrawEarthEntityHUD();

	StartTimers();

	UpdateMeteorSpawning();

	UpdateBuffSpawning();

	if (m_GameTimer.IsExpired())
	{
		EndGame();
	}
	else if (m_Player.GetHealth() <= 0)
	{
		GameOver();
	}
}

void Game::RestartGame()
{
	m_ApplicationState.SetCurrentState(GameStateID::PLAYING);
	m_GameTimer.Reset();
	m_MeteorsSpawnTimer.Reset();
	m_Player.SetScore(GameConfig::INIT_SCORE);
	m_Player.SetHealth(GameConfig::INIT_HEALTH);
}

void Game::HandleInput(const sf::Event& event)
{
	m_MeteorManager.HandleClick(event);
	m_BuffManager.HandleClick(event);

	if (m_EndGameScore)
	{
		m_EndGameScore->HandleInput(event);
	}
}

void Game::ShowScoreBoard()
{
	if (!m_EndGameScore)
	{
		m_EndGameScore = std::make_unique<EndGameScoreHUD>(m_ApplicationState, m_Player);
	}

	m_EndGameScore->Draw(m_Window);
}

void Game::DrawTopBarHUD()
{
	m_TopBarHUD.SetPlayerScore(m_Player.GetScore());
	m_TopBarHUD.SetPlayerLife(m_Player.GetHealth());
	m_TopBarHUD.SetGameTime(m_GameTimer.GetLeftTime());
	m_TopBarHUD.SetBuffSlot(m_Affect.GetActiveAffect());
	m_TopBarHUD.Draw();
}

void Game::DrawEarthEntityHUD()
{
	m_EarthEntityHUD.Draw(m_Window);
}

void Game::StartTimers()
{
	if (!m_GameTimer.IsActive())
	{
		m_GameTimer.Start();
	}

	if (!m_MeteorsSpawnTimer.IsActive())
	{
		m_MeteorsSpawnTimer.Start();
	}

	if (!m_BuffsSpawnTimer.IsActive())
	{
		m_BuffsSpawnTimer.Start();
	}
}

void Game::Update(float deltaTime)
{
	m_MeteorManager.Update(deltaTime);
	m_MeteorsSpawnTimer.Update(deltaTime);
	m_TopBarHUD.Update(deltaTime);
	m_GameTimer.Update(deltaTime);
	m_BuffManager.Update(deltaTime);
	m_BuffsSpawnTimer.Update(deltaTime);
	m_EarthEntityHUD.Update(deltaTime);
}

void Game::UpdateMeteorSpawning()
{
	m_MeteorManager.SetMeteorTypes(AssetSettings::METEOR::METEOR_TYPES);

	if (m_MeteorsSpawnTimer.IsExpired())
	{
		m_MeteorManager.SpawnMeteor();
		m_MeteorsSpawnTimer.Reset();
	}

	m_MeteorManager.DrawMeteors(m_Window);

	m_MeteorManager.CheckCollisions();
}

void Game::UpdateBuffSpawning()
{
	m_BuffManager.SetBuffTypes(AssetSettings::BUFF::BUFF_TYPES);

	if (m_BuffsSpawnTimer.IsExpired())
	{
		m_BuffManager.SpawnBuff();
		m_BuffsSpawnTimer.Reset();
	}

	m_BuffManager.DrawBuffs(m_Window);
}

void Game::ResetSpawners()
{
	m_MeteorsSpawnTimer.Reset();
	m_BuffsSpawnTimer.Reset();

	m_MeteorManager.ClearMeteors();
	m_BuffManager.ClearBuffs();
}

void Game::StopTimers()
{
	m_GameTimer.Stop();
	m_MeteorsSpawnTimer.Stop();
	m_BuffsSpawnTimer.Stop();
}

void Game::EndGame()
{
	StopTimers();
	ResetSpawners();
	m_ApplicationState.SetCurrentState(GameStateID::END_GAME_SCORE);
}

void Game::GameOver()
{
	StopTimers();
	ResetSpawners();
	m_ApplicationState.SetCurrentState(GameStateID::GAME_OVER);
}