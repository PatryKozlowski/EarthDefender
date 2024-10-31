#include "ui/MeteorHealthHUD.hpp"

MeteorHealthHUD::MeteorHealthHUD()
	: m_HealthText{ std::make_unique<Text>() },
	m_Heart{ std::make_unique<Heart>() },
	m_Animation{ 0.5f, 0.1f, false }
{
}

void MeteorHealthHUD::Draw(sf::RenderWindow& window)
{
	m_Heart->Draw(window);
	m_HealthText->Draw(window);
}

void MeteorHealthHUD::Update(float deltaTime)
{
	if (IsAnimating())
	{
		SetAnimationSpeed(GetAnimationSpeed() - deltaTime);

		SetScaleFactor(GetScaleFactor() + deltaTime * 0.55f);

		if (GetScaleFactor() >= 0.65)
		{
			SetIsAnimating(false);
			SetScaleFactor(0.5f);
		}
	}
}

void MeteorHealthHUD::UpdateHealthText(const unsigned int& health)
{
	m_HealthText->SetText(std::to_string(health));
}

void MeteorHealthHUD::InitMeteorHealthHUD(sf::Vector2f position, const unsigned int& health)
{
	m_Heart->SetObjectPosition(position.x, position.y - 15);
	m_Heart->SetObjectScale(GetScaleFactor(), GetScaleFactor());

	const float heartIconWidth = m_Heart->GetObjectBound().width;

	m_HealthText->SetText(std::to_string(health));
	m_HealthText->SetPosition(sf::Vector2f(position.x + heartIconWidth + 5, position.y - 16));
	m_HealthText->SetSize(16);
	m_HealthText->SetColor(sf::Color::White);
}

void MeteorHealthHUD::StartAnimation()
{
	SetIsAnimating(true);
	SetAnimationSpeed(0.1f);
}
