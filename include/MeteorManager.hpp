#pragma once

#include "Meteor.hpp"
#include <vector>
#include "Player.hpp"
#include "GameConfig.hpp"
#include "ui/EarthEntityHUD.hpp"
#include "Boss.hpp"

class MeteorManager
{
public:
	MeteorManager(sf::RenderWindow& window, Player& m_Player, Affect& affect, EarthEntityHUD& earthEntity, Boss& boss);
	void SpawnMeteor();
	void Update(float deltaTime);
	void DrawMeteors(sf::RenderWindow& window) const;
	void HandleClick(const sf::Event& event);
	void SetMeteorTypes(const std::vector<MeteorData>& meteorTypes);
	void CheckCollisions();
	void ClearMeteors();
	void IncrementScore(unsigned int meteorScore);
	void DecreaseHealth(unsigned int meteorDamage);
	std::vector<std::unique_ptr<Meteor>>& GetMeteors() { return m_Meteors; };

private:
	sf::RenderWindow& m_Window;
	std::vector<std::unique_ptr<Meteor>> m_Meteors;
	std::vector<MeteorData> m_MeteorTypes;
	Player& m_Player;
	Affect& m_Affect;
	EarthEntityHUD& m_EarthEntity;
	Boss& m_Boss;

	bool IsCollision(const Meteor& meteor, const Earth& earth);
};