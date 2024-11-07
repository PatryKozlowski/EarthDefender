#pragma once

#include "GameConfig.hpp"


class ApplicationState
{
public:
	ApplicationState(GameStateID state);

	inline GameStateID GetCurrentState() const { return m_currentState; }
	inline void SetCurrentState(GameStateID state) { m_currentState = state; }

private:
	GameStateID m_currentState;
};