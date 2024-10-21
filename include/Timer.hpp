#pragma once

class Timer
{
public:
    Timer(float duration);
    void Start();
    void Stop();
    void Update(float deltaTime);
    float GetElapsedTime() const;
    bool IsExpired();
    void Reset();

private:
    float m_ElapsedTime;
    float m_Duration;
    bool m_IsActive;
};