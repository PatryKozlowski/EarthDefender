#include "ui/MeteorHealthHUD.hpp"

MeteorHealthHUD::MeteorHealthHUD()
	: m_HealthText(std::make_unique<Text>()),
	m_Heart(std::make_unique<Heart>(0.0f, 0.0f)),
	m_ScaleFactor{ 0.5f },
	m_AnimatonSpeed{ 0.1f },
	m_IsAnimating{ false }
{
}

void MeteorHealthHUD::Draw(sf::RenderWindow& window)
{
	m_Heart->Draw(window);
	m_HealthText->Draw(window);
}

void MeteorHealthHUD::Update(float deltaTime)
{
	if (m_IsAnimating)
	{
		m_AnimatonSpeed -= deltaTime;
		if (m_AnimatonSpeed > 0.0f)
		{
			m_ScaleFactor = 0.64f;
		}
		else
		{
			m_ScaleFactor = 0.5f;
			m_IsAnimating = false;
		}

		m_Heart->SetObjectScale(m_ScaleFactor, m_ScaleFactor);
	}
}

void MeteorHealthHUD::UpdateHealthText(const unsigned int& health)
{
	m_HealthText->SetText(std::to_string(health));
}

void MeteorHealthHUD::InitMeteorHealthHUD(sf::Vector2f position, const unsigned int& health)
{
	m_Heart->SetObjectPosition(position.x, position.y - 15);
	m_Heart->SetObjectScale(m_ScaleFactor, m_ScaleFactor);

	const float heartIconWidth = m_Heart->GetObjectBound().width;

	m_HealthText->SetText(std::to_string(health));
	m_HealthText->SetPosition(sf::Vector2f(position.x + heartIconWidth + 5, position.y - 16));
	m_HealthText->SetSize(16);
	m_HealthText->SetColor(sf::Color::White);
}

void MeteorHealthHUD::StartAnimation()
{
	m_IsAnimating = true;
	m_AnimatonSpeed = 0.1f;
}
