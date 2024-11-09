#pragma once

#include "ui/StatElement.hpp"
#include "ui/icons/Clock.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

class GameTimeBar : public StatElement
{
public:
	GameTimeBar();

	void Update(float deltaTime);
	void StartAnimation();
	inline void SetTimeRemaining(float time) { m_Anmiation.timeRemaining = time; };
	inline void SetAnimating(bool isAnimating) { m_Anmiation.isAnimating = isAnimating; };
	inline void SetAnimationScale(float scale) { m_Anmiation.animationScale = scale; };
	inline void SetAnimationSpeed(float speed) { m_Anmiation.animationSpeed = speed; };
	inline float GetTimeRemaining() const { return m_Anmiation.timeRemaining; };
	inline float GetAnimationScale() const { return m_Anmiation.animationScale; };
	inline float GetAnimationSpeed() const { return m_Anmiation.animationSpeed; };
	inline bool IsAnimating() const { return m_Anmiation.isAnimating; };

private:
	struct Animation
	{
		float animationScale;
		float animationSpeed;
		bool isAnimating;
		float timeRemaining;
	} m_Anmiation;
};