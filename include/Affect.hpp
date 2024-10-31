#pragma once

#include "GameConfig.hpp"

class Affect
{
public:
	Affect() = default;

	inline void SetDoubleScore(bool isDoubleScore) { m_Buffs.doubleScore = isDoubleScore; }
	inline bool IsDoubleScore() const { return m_Buffs.doubleScore; }

	inline void SetDoubleDamage(bool isDoubleDamage) { m_Buffs.doubleDamage = isDoubleDamage; }
	inline bool IsDoubleDamage() const { return m_Buffs.doubleDamage; }

	inline void SetInvincible(bool isInvincible) { m_Buffs.invincible = isInvincible; }
	inline bool IsInvincible() const { return m_Buffs.invincible; }

	inline void SetSlowBuff(bool isSlowBuff) { m_Buffs.isSlowBuff = isSlowBuff; };
	inline bool IsSlowBuff() const { return m_Buffs.isSlowBuff; };

	void ApplyEffect(const BuffTypeID& buffType);
	void RemoveEffect(const BuffTypeID& buffType);

	BuffTypeID GetActiveAffect() const;

private:
	struct Buffs
	{
		bool doubleScore = false;
		bool doubleDamage = false;
		bool invincible = false;
		bool isSlowBuff = false;
	} m_Buffs;
};