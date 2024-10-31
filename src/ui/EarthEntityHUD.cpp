#include "ui/EarthEntityHUD.hpp"

EarthEntityHUD::EarthEntityHUD(Affect& affect)
	: m_Affect{ affect },
	m_ShieldHUD{ std::nullopt },
	m_Earth{}
{
}

void EarthEntityHUD::Draw(sf::RenderWindow& window) const
{
	m_Earth.Draw(window);

	if (m_ShieldHUD)
	{
		m_ShieldHUD->Draw(window);
	}
}

void EarthEntityHUD::Update(float deltaTime)
{
	if (m_Affect.IsInvincible() && !m_ShieldHUD)
	{
		m_ShieldHUD.emplace(m_Earth);
	}
	else if (!m_Affect.IsInvincible() && m_ShieldHUD)
	{
		m_ShieldHUD.reset();
	}
}
