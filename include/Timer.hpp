#pragma once

class Timer
{
public:
	Timer(const float& duration);
	void Update(const float& deltaTime);
	inline void Reset() { m_ElapsedTime = 0.0f; };
	inline void Start() { m_IsActive = true; };
	inline void Stop() { m_IsActive = false; };
	inline float GetElapsedTime() const { return m_ElapsedTime; };
	inline float GetLeftTime() const { return m_Duration - m_ElapsedTime; };
	inline float GetDuration() const { return m_Duration; };
	inline bool IsActive() const { return m_IsActive; };
	inline bool IsExpired() const { return m_ElapsedTime >= m_Duration; };

private:
	float m_ElapsedTime;
	float m_Duration;
	bool m_IsActive;
};