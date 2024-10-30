#pragma once

#include "Object.hpp"
#include "GameConfig.hpp"
#include "Player.hpp"

class Buff : public Object
{
public:
	Buff(const std::string& pathName, BuffTypeID type, float duration);

	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) const override;
	void ApplyEffect(Player& player);
	void RemoveEffect(Player& player);
	void StartAnimation();
	inline void SetActive(bool isActive) { m_IsActive = isActive; };
	inline void Collect() { m_IsCollected = true; };
	inline bool IsCollected() const { return m_IsCollected; };
	inline bool IsDestroyed() const { return m_Destroyed; };
	inline void SetToDestroy() { m_Destroyed = true; };
	inline bool IsAcitve() const { return m_IsActive; };
	inline bool IsAnimating() const { return m_IsAnimating; };
	inline void SetAnimating(bool isAnimating) { m_IsAnimating = isAnimating; };

private:
	BuffTypeID m_Type;
	float m_Duration;
	float m_TimeToCollect;
	bool m_Destroyed;
	bool m_IsActive;
	bool m_IsCollected;
	float m_AnimationScale;
	float m_AnimationSpeed;
	bool m_IsAnimating;

	void SetRandomPosition();
};