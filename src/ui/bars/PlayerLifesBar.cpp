#include "ui/bars/PlayerLifesBar.hpp"
#include "GameConfig.hpp"
#include <iostream>

PlayerLifesBar::PlayerLifesBar()
	: m_ScaleFactor{ 1.0 },
	m_AnimationSpeed{ 0.1f },
	m_IsAnimating{ false }
{
}

void PlayerLifesBar::Draw(sf::RenderWindow& window) const
{
	for (const auto& heart : m_Hearts)
	{
		auto bounds = heart->GetObjectBound();
		heart->SetObjectOrigin(bounds.width / 2, bounds.height / 2);
		heart->Draw(window);
	}
}

void PlayerLifesBar::Update(float deltaTime)
{
	if (m_IsAnimating)
	{
		m_AnimationSpeed -= deltaTime;

		m_ScaleFactor += deltaTime * 1.20f;
		m_Hearts.back()->SetObjectScale(m_ScaleFactor, m_ScaleFactor);

		if (m_ScaleFactor >= 1.35f)
		{
			m_IsAnimating = false;
			m_ScaleFactor = 1.0f;
			m_Hearts.pop_back();
		}
	}
}

void PlayerLifesBar::SetLife(unsigned int livesCount)
{
	const float heartSpacing = 20.0f;

	if (livesCount < m_Hearts.size())
	{
		StartAnimation();
	}
	else
	{
		m_Hearts.clear();

		for (unsigned int i = 0; i < livesCount; ++i)
		{
			auto heart = std::make_unique<Heart>();
			heart->SetObjectPosition(AssetSettings::HEART::X_OFFSET + 10 + i * 40, TopBarHUDConfig::BACKGROUND_Y_OFFSET / 2);
			m_Hearts.push_back(std::move(heart));
		}
	}
}

void PlayerLifesBar::StartAnimation()
{
	m_IsAnimating = true;
}