#pragma once

#include "Object.hpp"
#include "AssetManager.hpp"
#include "GameConfig.hpp"

class Explosion : public Object
{
public:
	Explosion(bool isMeteorExplosionByPlayer);

	void Update(float deltaTime) override;
	inline void SetFinished(bool isFinished) { m_Animation.isFinished = isFinished; };
	inline void SetExplosionByPlayer(bool isExplosionByPlayer) { m_IsExplosionByPlayer = isExplosionByPlayer; };
	inline void SetCurrentFrame(unsigned int currentFrame) { m_Animation.currentFrame = currentFrame; };
	inline void SetElapsedTime(float elapsedTime) { m_Animation.elapsedTime = elapsedTime; };
	inline void SetFrameDuration(float frameDuration) { m_Animation.frameDuration = frameDuration; };
	inline bool IsExplosionByPlayer() const { return m_IsExplosionByPlayer; };
	inline bool IsFinished() const { return m_Animation.isFinished; };
	inline unsigned int GetCurrentFrame() const { return m_Animation.currentFrame; };
	inline float GetElapsedTime() const { return m_Animation.elapsedTime; };
	inline float GetFrameDuration() const { return m_Animation.frameDuration; };

private:
	bool m_IsExplosionByPlayer;

	struct Animation
	{
		bool isFinished;
		float elapsedTime;
		float frameDuration;
		unsigned int currentFrame;
	} m_Animation;

	void UpdateTextureRect();
};