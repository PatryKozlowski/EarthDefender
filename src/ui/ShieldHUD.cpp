#include "ui/ShieldHUD.hpp"

ShieldHUD::ShieldHUD(Earth& earth)
	: m_Shield{ std::make_unique<Shield>() },
	m_Earth{ earth }
{
}

void ShieldHUD::Draw(sf::RenderWindow& window) const
{
	float xPosition = m_Earth.GetObjectPosition().x + m_Earth.GetObjectBound().width / 2.0f - m_Shield->GetObjectBound().width / 2.0f;
	float yPosition = m_Earth.GetObjectPosition().y - m_Shield->GetObjectBound().height / 2.0f + m_Earth.GetObjectRadius();

	m_Shield->SetObjectPosition(xPosition, yPosition);
	m_Shield->Draw(window);
}
