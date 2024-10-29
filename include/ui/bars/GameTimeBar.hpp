#pragma once

#include "ui/StatElement.hpp"

class GameTimeBar : public StatElement
{
public:
	GameTimeBar();

	void Update(float deltaTime);
	void StartAnimation();

private:
	float m_AnimationScale;
	float m_AnimationSpeed;
	bool m_IsAnimating;
	float m_TimeRemaining;
};