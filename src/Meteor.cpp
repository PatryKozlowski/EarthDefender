#include "Meteor.hpp"
#include "GameConfig.hpp"
#include <AssetManager.hpp>
#include <iostream>

Meteor::Meteor(const sf::Texture& texture, float speed, unsigned int health, unsigned int damage, unsigned int score)
	:m_Speed{ speed },
	m_Health{ health },
	m_Damage{ damage },
	m_Score{ score },
	m_Destroyed{ false },
	m_HealthHUD{ std::make_unique<MeteorHealthHUD>() },
	m_Explosion{ nullptr },
	m_HasExploded{ false }
{
	AssetManager::GetInstance().LoadTexture(AssetSettings::EXPLOSION::TEXTURE_PATH);

	SetObjectTexture(texture);

	SetRandomPosition();

	m_Radius = GetObjectBound().width / 2.0f;
}

void Meteor::Update(float deltaTime)
{
	if (m_Explosion)
	{
		m_Explosion->Update(deltaTime);

		if (m_Explosion->IsFinished())
		{
			m_Destroyed = true;
			m_Explosion.reset();
		}
	}

	if (!HasExploded())
	{
		Move(deltaTime);
		m_HealthHUD->Update(deltaTime);
	}
}

void Meteor::Draw(sf::RenderWindow& window)
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
		m_HealthHUD->InitMeteorHealthHUD(GetObjectPosition(), m_Health);

		m_HealthHUD->Draw(window);
	}
}

void Meteor::SetRandomPosition()
{
	unsigned int meteorRadius = static_cast<unsigned int>(GetObjectBound().width / 2);
	unsigned int xPosition = static_cast<unsigned int>(rand()) % (WindowConfig::WIDTH - meteorRadius * 2);

	float yPosition = (GamePlayHUDConfig::BACKGROUND_Y_OFFSET + 5.0f);

	SetObjectPosition(static_cast<float>(xPosition), yPosition);
}

void Meteor::Move(float deltaTime)
{
	float positionX = GetObjectPosition().x;
	float positionY = GetObjectPosition().y;

	float speed = m_Speed * deltaTime;

	SetObjectPosition(positionX, positionY + speed);
}

void Meteor::Explode(bool isMeteorExplosionByPlayer)
{
	if (isMeteorExplosionByPlayer)
	{
		m_Explosion = std::make_unique<Explosion>(true);
		m_Explosion->SetPosition(GetObjectPosition());
	}
	else
	{
		m_Explosion = std::make_unique<Explosion>(false);
		float offsetY = m_Radius;

		sf::Vector2f explosionPosition = GetObjectPosition();
		explosionPosition.y += offsetY;

		m_Explosion->SetPosition(explosionPosition);
	}

	m_HasExploded = true;
}

void Meteor::Destroy()
{
	m_Destroyed = true;
}

void Meteor::TakeDamage(const unsigned int& damage)
{
	if (m_Health > 0)
	{
		m_Health -= damage;
		UpdateHealthText(m_Health);
	}

	if (m_Health <= 0 && !HasExploded())
	{
		Explode(true);
	}
}

void Meteor::UpdateHealthText(const unsigned int& health)
{
	m_HealthHUD->StartAnimation();
	m_HealthHUD->UpdateHealthText(health);
}

unsigned int Meteor::GetHealth() const
{
	return m_Health;
}

unsigned int Meteor::GetDamage() const
{
	return m_Damage;
}

unsigned int Meteor::GetScore() const
{
	return m_Score;
}

float Meteor::GetRadius() const
{
	return m_Radius;
}

bool Meteor::IsDestroyed() const
{
	bool meteorOutSideWindow = GetObjectPosition().y >= WindowConfig::HEIGHT;

	if (HasExploded() && (!m_Explosion || m_Explosion->IsFinished())) {
		return true;
	}

	return meteorOutSideWindow || m_Destroyed;
}

bool Meteor::IsClicked(const sf::Vector2i& mousePosition) const
{
	auto meteorPosition = GetObjectPosition();
	float meteorRadius = m_Radius;
	float meteorPositionX = meteorPosition.x;
	float meteorPositionY = meteorPosition.y;
	float meteorCenterX = meteorPositionX + meteorRadius;
	float meteorCenterY = meteorPositionY + meteorRadius;
	float mousePositionX = mousePosition.x;
	float mousePositionY = mousePosition.y;
	auto meteorCenter = sf::Vector2f(meteorCenterX, meteorCenterY);

	float distance = std::sqrt(std::pow(mousePositionX - meteorCenterX, 2) + std::pow(mousePositionY - meteorCenterY, 2));

	return distance <= meteorRadius;
}

bool Meteor::HasExploded() const
{
	return m_HasExploded;
}
