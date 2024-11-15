#include "Boss.hpp"

Boss::Boss(Player& player, Affect& affect)
	: m_IsSpawned{ false },
	m_HealthHUD{ std::make_unique<EnemyHealthHUD>() },
	m_Explosion{ nullptr },
	m_HasExploded{ false },
	m_ShouldAppear{ true },
	m_Player{ player },
	m_Affect{ affect },
	m_Stats{ GameConfig::BOSS_HEALTH, GameConfig::BOSS_SCORE }
{
}

void Boss::SpawnBoss(sf::RenderWindow& window)
{
	if (!GetIsSpawned())
	{
		return;
	}

	if (m_Explosion)
	{
		m_Explosion->Draw(window);
	}
	else
	{
		m_Ufo.Draw(window);
		m_Affect.ApplyEffect(BuffTypeID::BOSS_METEOR_ENHANCEMENT);
	}

	if (!HasExploded())
	{
		m_HealthHUD->InitMeteorHealthHUD(m_Ufo.GetObjectPosition(), GetHealth());

		m_HealthHUD->Draw(window);
	}
}

void Boss::HandleClick(const sf::Event& event)
{
	if (!GetIsSpawned())
	{
		return;
	}

	if (m_Ufo.IsClicked(event) && !HasExploded())
	{
		Hit(m_Player.GetDamage());
	}

}

void Boss::Update(float deltaTime)
{
	if (!GetIsSpawned())
	{
		return;
	}

	if (m_Explosion)
	{
		m_Explosion->Update(deltaTime);

		if (m_Explosion->IsFinished())
		{
			SetIsSpawned(false);
			SetShouldAppear(false);
			m_Affect.RemoveEffect(BuffTypeID::BOSS_METEOR_ENHANCEMENT);
			m_Explosion.reset();
		}
	}

	if (!HasExploded())
	{
		m_HealthHUD->Update(deltaTime);
	}
}

void Boss::ResetBoss()
{
	SetHealth(GameConfig::BOSS_HEALTH);
	SetShouldAppear(true);
	SetIsSpawned(false);
	SetHasExploded(false);
}

void Boss::Hit(unsigned int damage)
{
	const unsigned int currentHealth = GetHealth();

	if (currentHealth > 0)
	{
		if (damage >= currentHealth)
		{
			SetHealth(0);
		}
		else
		{
			SetHealth(currentHealth - damage);
		}

		UpdateHealthText(currentHealth);

		if (GetHealth() == 0 && !HasExploded())
		{
			Explode();
			m_Player.SetScore(m_Player.GetScore() + GetScore());
		}
	}
}

void Boss::UpdateHealthText(const unsigned int& health)
{
	m_HealthHUD->StartAnimation();
	m_HealthHUD->UpdateHealthText(health);
}

void Boss::Explode()
{
	m_Explosion = std::make_unique<Explosion>(false);
	m_Explosion->SetObjectPosition(m_Ufo.GetObjectPosition().x + m_Ufo.GetObjectBound().width / 4, m_Ufo.GetObjectPosition().y + m_Ufo.GetObjectBound().height / 4);

	SetHasExploded(true);
}
