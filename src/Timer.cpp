#include "Timer.hpp"

Timer::Timer(const float& duration)
	: m_ElapsedTime{ 0.0f },
	m_Duration{ duration },
	m_IsActive{ false }
{
}

void Timer::Start()
{
	m_IsActive = true;
}

void Timer::Stop()
{
	m_IsActive = false;
}

bool Timer::IsExpired() const
{
	return m_ElapsedTime >= m_Duration;
}

void Timer::Reset()
{
	m_ElapsedTime = 0.0f;
}

void Timer::Update(const float& deltaTime)
{
	if (m_IsActive)
	{
		m_ElapsedTime += deltaTime;
	}
}

float Timer::GetElapsedTime() const
{
	return m_ElapsedTime;
}

bool Timer::IsActive() const
{
	return m_IsActive;
}

float Timer::GetLeftTime() const
{
	return m_Duration - m_ElapsedTime;
}

float Timer::GetDuration() const
{
	return m_Duration;
}


