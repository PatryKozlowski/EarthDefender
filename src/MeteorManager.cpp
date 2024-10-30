#include "MeteorManager.hpp"

MeteorManager::MeteorManager(sf::RenderWindow& window, Player& player)
	: m_Window{ window },
	m_Player{ player }
{
}

void MeteorManager::SpawnMeteor()
{
	if (m_MeteorTypes.empty())
	{
		return;
	}

	const MeteorData& randomMeteorData = m_MeteorTypes[static_cast<size_t>(rand() % static_cast<int>(m_MeteorTypes.size()))];

	m_Meteors.emplace_back(std::make_unique<Meteor>(randomMeteorData.texturePath, randomMeteorData.speed, randomMeteorData.health, randomMeteorData.damage, randomMeteorData.score));
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

void MeteorManager::HandleClick(sf::Vector2i& mousePosition)
{
	for (auto& meteor : m_Meteors)
	{
		if (meteor->IsClicked(mousePosition))
		{
			meteor->Hit(m_Player.GetDamage());
			meteor->UpdateHealthText(meteor->GetDamage());

			if (meteor->GetHealth() == 0)
			{
				IncrementScore(meteor->GetScore());
			}
		}
	}
}

void MeteorManager::SetMeteorTypes(const std::vector<MeteorData>& meteorTypes)
{
	m_MeteorTypes = meteorTypes;
}

void MeteorManager::CheckCollisions()
{
	for (auto& meteor : m_Meteors)
	{
		if (IsCollision(*meteor, m_Player.GetPlayerObject()))
		{
			if (!meteor->HasExploded())
			{
				meteor->Explode(false);
				DecreaseHealth(meteor->GetDamage());
			}
		}
	}
}

void MeteorManager::ClearMeteors()
{
	m_Meteors.clear();
}

void MeteorManager::IncrementScore(unsigned int meteorScore)
{
	m_Player.IncrementScore(meteorScore);
}

void MeteorManager::DecreaseHealth(unsigned int meteorDamage)
{
	m_Player.DecreaseHealth(meteorDamage);
}

bool MeteorManager::IsCollision(const Meteor& meteor, const Earth& earth)
{
	sf::Vector2f earthPosition = earth.GetObjectPosition();
	float earthRadius = earth.GetObjectRadius();
	float meteorRadius = meteor.GetObjectRadius();

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