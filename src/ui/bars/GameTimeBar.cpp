#include "ui/bars/GameTimeBar.hpp"

GameTimeBar::GameTimeBar()
	: StatElement(std::make_shared<Clock>()),
	m_Anmiation{ AssetSettings::CLOCK::SCALE, 0.1f, false, GameConfig::GAME_TIME }
{
}

void GameTimeBar::Update(float deltaTime)
{
	SetTimeRemaining(GetTimeRemaining() - deltaTime);

	if (GetTimeRemaining() <= 10.0f && GetTimeRemaining() > 0.0f)
	{
		StartAnimation();
	}
	else if (GetTimeRemaining() <= 0.0f)
	{
		SetAnimating(false);
	}

	if (IsAnimating())
	{
		SetAnimationScale(GetAnimationScale() + GetAnimationSpeed() * deltaTime * 2.0f);

		if (GetAnimationScale() >= 1.2f || GetAnimationScale() <= 1.0f)
		{
			SetAnimationSpeed(-GetAnimationSpeed());
		}

		GetIcon()->SetObjectScale(GetAnimationScale(), GetAnimationScale());
	}
}

void GameTimeBar::StartAnimation()
{
	SetAnimating(true);
}
