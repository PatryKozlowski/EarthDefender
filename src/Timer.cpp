#include "Timer.hpp"

Timer::Timer(const float& duration)
	: m_ElapsedTime{ 0.0f },
	m_Duration{ duration },
	m_IsActive{ false }
{
}

void Timer::Update(const float& deltaTime)
{
	if (IsActive())
	{
		m_ElapsedTime += deltaTime;
	}
}



