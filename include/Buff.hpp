#pragma once

#include "Object.hpp"
#include "GameConfig.hpp"
#include "Player.hpp"
#include "MeteorManager.hpp"

class Buff : public Object
{
public:
	Buff(const std::string& pathName, BuffTypeID type, float duration);

	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) const override;
	void UpdateAnimation(float deltaTime);
	inline void SetActive(bool isActive) { m_IsActive = isActive; };
	inline void Collect() { m_IsCollected = true; };
	inline void SetTimeToCollect(float time) { m_TimeToCollect = time; };
	inline void SetDuration(float duration) { m_Duration = duration; };
	inline void SetAnimationScale(float scale) { m_Animation.scale = scale; };
	inline void SetAnimationSpeed(float speed) { m_Animation.speed = speed; };
	inline bool IsCollected() const { return m_IsCollected; };
	inline bool IsDestroyed() const { return m_Destroyed; };
	inline void SetToDestroy() { m_Destroyed = true; };
	inline bool IsActive() const { return m_IsActive; };
	inline bool IsAnimating() const { return m_Animation.isAnimating; };
	inline void SetAnimating(bool isAnimating) { m_Animation.isAnimating = isAnimating; };
	inline BuffTypeID GetBuffType() const { return m_Type; };
	inline float GetDuration() const { return m_Duration; };
	inline float GetTimeToCollect() const { return m_TimeToCollect; };
	inline float GetAnimationScale() const { return m_Animation.scale; };
	inline float GetAnimationSpeed() const { return m_Animation.speed; };

private:
	BuffTypeID m_Type;
	float m_Duration;
	float m_TimeToCollect;
	bool m_Destroyed;
	bool m_IsActive;
	bool m_IsCollected;

	struct Animation {
		float scale;
		float speed;
		bool isAnimating;
	} m_Animation;

	void SetRandomPosition();
};