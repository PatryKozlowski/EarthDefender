#include "BuffManager.hpp"

BuffManager::BuffManager(sf::RenderWindow& window, Player& player, Affect& affect)
	: m_Window{ window },
	m_Player{ player },
	m_Affect{ affect }
{
}


void BuffManager::Update(float deltaTime)
{
	for (auto& buff : m_Buffs)
	{
		buff->Update(deltaTime);

		if (buff->IsDestroyed())
		{
			m_Affect.RemoveEffect(buff->GetBuffType());
		}
	}

	m_Buffs.erase(
		std::remove_if(m_Buffs.begin(), m_Buffs.end(), [](const std::unique_ptr<Buff>& buff)
			{return buff->IsDestroyed();}),
		m_Buffs.end()
	);
}

void BuffManager::DrawBuffs(sf::RenderWindow& window) const
{
	for (const auto& buff : m_Buffs)
	{
		buff->Draw(window);
	}
}

void BuffManager::SpawnBuff()
{
	if (m_BuffTypes.empty())
	{
		return;
	}

	const BuffData& randomBuffDate = m_BuffTypes[static_cast<size_t>(rand() % static_cast<int>(m_BuffTypes.size()))];

	m_Buffs.emplace_back(std::make_unique<Buff>(randomBuffDate.texturePath, randomBuffDate.id, randomBuffDate.duration));
}

void BuffManager::SetBuffTypes(const std::vector<BuffData>& buffTypes)
{
	m_BuffTypes = buffTypes;
}

void BuffManager::HandleClick(const sf::Event& event)
{
	for (auto& buff : m_Buffs)
	{
		if (buff->IsClicked(event))
		{
			buff->SetActive(true);
			buff->Collect();
			m_Affect.ApplyEffect(buff->GetBuffType());
		}
	}
}

void BuffManager::ClearBuffs()
{
	m_Buffs.clear();
}
