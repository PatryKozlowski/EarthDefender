#pragma once

class Timer
{
public:
	Timer(const float& duration);
	void Start();
	void Stop();
	void Update(const float& deltaTime);
	float GetElapsedTime() const;
	bool IsExpired() const;
	void Reset();
	bool IsActive() const;
	float GetLeftTime() const;
	float GetDuration() const;

private:
	float m_ElapsedTime;
	float m_Duration;
	bool m_IsActive;
};