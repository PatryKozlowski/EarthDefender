#include "MeteorManager.hpp"
#include "AssetManager.hpp"
#include <iostream>

MeteorManager::MeteorManager(sf::RenderWindow& window)
	: m_Window(window)
{
}

void MeteorManager::SpawnMeteor()
{
	if (m_MeteorTypes.empty())
	{
		return;
	}

	const MeteorData& randomMeteorData = m_MeteorTypes[static_cast<size_t>(rand() % static_cast<int>(m_MeteorTypes.size()))];

	const sf::Texture& meteorTexture = AssetManager::GetInstance().GetTexture(randomMeteorData.texturePath);

	m_Meteors.emplace_back(std::make_unique<Meteor>(meteorTexture, randomMeteorData.speed, randomMeteorData.health, randomMeteorData.damage, randomMeteorData.score));
}

void MeteorManager::Update(float deltaTime)
{
	for (auto& meteor : m_Meteors)
	{
		meteor->Update(deltaTime);
	}

	m_Meteors.erase(
		std::remove_if(m_Meteors.begin(), m_Meteors.end(), [](const std::unique_ptr<Meteor>& meteor)
			{ return meteor->IsDestroyed(); }),
		m_Meteors.end());
}

void MeteorManager::DrawMeteors(sf::RenderWindow& window) const
{
	for (const auto& meteor : m_Meteors)
	{
		meteor->Draw(window);
	}
}

void MeteorManager::HandleClick(sf::Vector2i& mousePosition, unsigned int& playerScore)
{
	for (auto& meteor : m_Meteors)
	{
		if (meteor->IsClicked(mousePosition))
		{
			meteor->TakeDamage(1);
			meteor->UpdateHealthText(meteor->GetDamage());

			if (meteor->GetHealth() == 0)
			{
				playerScore += meteor->GetScore();
			}
		}
	}

	m_Meteors.erase(
		std::remove_if(m_Meteors.begin(), m_Meteors.end(), [](const std::unique_ptr<Meteor>& meteor)
			{ return meteor->IsDestroyed(); }),
		m_Meteors.end());
}

void MeteorManager::SetMeteorTypes(const std::vector<MeteorData>& meteorTypes)
{
	m_MeteorTypes = meteorTypes;
}

void MeteorManager::CheckCollisions(const Earth& earth, unsigned int& playerLife)
{
	for (auto& meteor : m_Meteors)
	{
		if (IsCollision(*meteor, earth))
		{
			if (!meteor->HasExploded())
			{
				meteor->Explode(false);
				playerLife -= meteor->GetDamage();
			}
		}
	}
}

void MeteorManager::ClearMeteors()
{
	m_Meteors.clear();
}

bool MeteorManager::IsCollision(const Meteor& meteor, const Earth& earth)
{
	sf::Vector2f earthPosition = earth.GetObjectPosition();
	float earthRadius = earth.GetRadius();
	float meteorRadius = meteor.GetRadius();

	float earthCenterX = earthPosition.x + earthRadius;
	float earthCenterY = earthPosition.y + earthRadius;

	sf::Vector2f meteorPosition = meteor.GetObjectPosition();
	float meteorCenterX = meteorPosition.x + meteorRadius;
	float meteorCenterY = meteorPosition.y + meteorRadius;

	float dx = meteorCenterX - earthCenterX;
	float dy = meteorCenterY - earthCenterY;
	float distanceSquared = dx * dx + dy * dy;

	float radiiSum = earthRadius + meteorRadius;
	return distanceSquared < (radiiSum * radiiSum);
}