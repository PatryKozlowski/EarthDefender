#include "ui/bars/GameTimeBar.hpp"
#include "ui/icons/Clock.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"
#include <iostream>

GameTimeBar::GameTimeBar() :
	StatElement(std::make_shared<Clock>()),
	m_AnimationScale{ AssetSettings::CLOCK::SCALE },
	m_AnimationSpeed{ 0.1f },
	m_IsAnimating{ false },
	m_TimeRemaining{ GameConfig::GAME_TIME }
{
}

void GameTimeBar::Update(float deltaTime)
{
	m_TimeRemaining -= deltaTime;
	if (m_TimeRemaining <= 10.0f && m_TimeRemaining > 0.0f)
	{
		StartAnimation();
	}
	else if (m_TimeRemaining <= 0.0f)
	{
		m_IsAnimating = false;
	}

	if (m_IsAnimating)
	{
		m_AnimationScale += m_AnimationSpeed * deltaTime * 2.0f;

		if (m_AnimationScale >= 1.2f || m_AnimationScale <= 1.0f)
		{
			m_AnimationSpeed = -m_AnimationSpeed;
		}

		GetIcon()->SetObjectScale(m_AnimationScale, m_AnimationScale);
	}
}

void GameTimeBar::StartAnimation()
{
	m_IsAnimating = true;
}
