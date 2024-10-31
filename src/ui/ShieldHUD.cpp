#include "ui/ShieldHUD.hpp"

#include "GameConfig.hpp"
#include <sstream>
#include <iomanip>

ShieldHUD::ShieldHUD(Earth& earth, Affect& affect)
	: m_Shield{ std::make_unique<Shield>() },
	m_Earth{ earth },
	m_Affect{ affect },
	m_Text{ std::make_unique<Text>() },
	m_ShieldTime{ AssetSettings::BUFF::INVINCIBILITY::DURATION }
{
}

void ShieldHUD::Update(float deltaTime)
{
	SetTextContent(deltaTime);
}

void ShieldHUD::Draw(sf::RenderWindow& window) const
{
	SetShieldObject();
	SetTextObject();

	m_Shield->Draw(window);
	m_Text->Draw(window);

}

void ShieldHUD::SetShieldObject() const
{
	float xPosition = m_Earth.GetObjectPosition().x + m_Earth.GetObjectBound().width / 2.0f - m_Shield->GetObjectBound().width / 2.0f;
	float yPosition = m_Earth.GetObjectPosition().y - m_Shield->GetObjectBound().height / 2.0f + m_Earth.GetObjectRadius();

	m_Shield->SetObjectPosition(xPosition, yPosition);
}

void ShieldHUD::SetTextObject() const
{
	float xTextPosition = WindowConfig::WIDTH / 2.0f - m_Earth.GetObjectBound().width / 2.0f + m_Earth.GetObjectRadius() - 18.0f;
	float yTextPosition = WindowConfig::HEIGHT - m_Earth.GetObjectBound().height + 64.0f + m_Text->GetBound().width / 6.0f;

	m_Text->SetColor(sf::Color::Black);
	m_Text->SetSize(18);
	m_Text->SetPosition(sf::Vector2f(xTextPosition, yTextPosition));
}

void ShieldHUD::SetTextContent(float deltaTime)
{
	if (m_Affect.IsInvincible())
	{
		if (GetShieldTime() <= 0.0f)
		{
			SetShieldTime(AssetSettings::BUFF::INVINCIBILITY::DURATION);
		}

		SetShieldTime(GetShieldTime() - deltaTime);
		if (GetShieldTime() < 0.0f)
		{
			SetShieldTime(0.0f);
		}

		std::ostringstream stream;
		stream << std::fixed << std::setprecision(2) << GetShieldTime();

		m_Text->SetText(stream.str());
	}
	else
	{
		m_ShieldTime = 0.0f;
	}
}
