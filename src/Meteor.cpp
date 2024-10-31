#include "Meteor.hpp"
#include "GameConfig.hpp"

Meteor::Meteor(Affect& affect, const std::string& pathName, float speed, unsigned int health, unsigned int damage, unsigned int score)
	: Object(pathName, AssetSettings::METEOR::SCALE, 0.0f, 0.0f),
	m_Affect{ affect },
	m_Stats{ speed, health, damage, score },
	m_Destroyed{ false },
	m_HealthHUD{ std::make_unique<MeteorHealthHUD>() },
	m_Explosion{ nullptr },
	m_HasExploded{ false }
{
	SetRandomPosition();
}

void Meteor::Update(float deltaTime)
{
	if (m_Explosion)
	{
		m_Explosion->Update(deltaTime);

		if (m_Explosion->IsFinished())
		{
			SetDestroyed(true);
			m_Explosion.reset();
		}
	}

	if (!HasExploded())
	{
		Move(deltaTime);
		m_HealthHUD->Update(deltaTime);
	}
}

void Meteor::Draw(sf::RenderWindow& window) const
{
	if (m_Explosion)
	{
		m_Explosion->Draw(window);
	}
	else
	{
		Object::Draw(window);
	}

	if (!HasExploded())
	{
		m_HealthHUD->InitMeteorHealthHUD(GetObjectPosition(), GetHealth());

		m_HealthHUD->Draw(window);
	}
}

void Meteor::SetRandomPosition()
{
	unsigned int meteorRadius = static_cast<unsigned int>(GetObjectBound().width / 2);
	unsigned int xPosition = static_cast<unsigned int>(rand()) % (WindowConfig::WIDTH - meteorRadius * 2);

	float yPosition = (TopBarHUDConfig::BACKGROUND_Y_OFFSET + 5.0f);

	SetObjectPosition(static_cast<float>(xPosition), yPosition);
}

void Meteor::Move(float deltaTime)
{
	float positionX = GetObjectPosition().x;
	float positionY = GetObjectPosition().y;

	if (m_Affect.IsSlowBuff())
	{
		positionY += GetSpeed() * deltaTime * AssetSettings::BUFF::SLOW_METEOR_SPEED::SPEED_MULTIPLIER;
	}
	else
	{
		positionY += GetSpeed() * deltaTime;
	}

	SetObjectPosition(positionX, positionY);
}

void Meteor::Explode(bool isMeteorExplosionByPlayer)
{
	if (isMeteorExplosionByPlayer)
	{
		m_Explosion = std::make_unique<Explosion>(true);
		m_Explosion->SetObjectPosition(GetObjectPosition().x, GetObjectPosition().y);
	}
	else
	{
		m_Explosion = std::make_unique<Explosion>(false);
		float offsetY = GetObjectRadius();

		sf::Vector2f explosionPosition = GetObjectPosition();
		explosionPosition.y += offsetY;

		m_Explosion->SetObjectPosition(explosionPosition.x, explosionPosition.y);
	}

	SetHasExploded(true);
}

void Meteor::Hit(unsigned int damage)
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
			Explode(true);
		}
	}
}

void Meteor::UpdateHealthText(const unsigned int& health)
{
	m_HealthHUD->StartAnimation();
	m_HealthHUD->UpdateHealthText(health);
}

bool Meteor::IsDestroyed() const
{
	bool meteorOutSideWindow = GetObjectPosition().y >= WindowConfig::HEIGHT;

	if (HasExploded() && (!m_Explosion || m_Explosion->IsFinished())) {
		return true;
	}

	return meteorOutSideWindow || GetDestroyedFlag();
}
