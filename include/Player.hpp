#pragma once

#include "ui/Earth.hpp"

class Player
{
public:
	Player();

	void SpawnPlayer(sf::RenderWindow& window);
	unsigned int GetHealth() const { return m_Health; };
	unsigned int GetScore() const { return m_Score; };
	void SetHealth(unsigned int health) { m_Health = health; };
	void SetScore(unsigned int score) { m_Score = score; };
	void DecreaseHealth(unsigned int damage) { m_Health -= damage; };
	void IncrementScore(unsigned int score) { m_Score += score; };
	Earth& GetPlayerObject() { return *m_Earth; };

private:
	std::unique_ptr<Earth> m_Earth;
	unsigned int m_Health;
	unsigned int m_Score;
};