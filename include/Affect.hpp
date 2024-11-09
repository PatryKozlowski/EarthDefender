#pragma once

#include "GameConfig.hpp"

class Affect
{
public:
	Affect() = default;

	inline bool IsDoubleScore() const { return m_Buffs.doubleScore; }
	inline void SetDoubleDamage(bool isDoubleDamage) { m_Buffs.doubleDamage = isDoubleDamage; }
	inline bool IsDoubleDamage() const { return m_Buffs.doubleDamage; }
	inline bool IsInvincible() const { return m_Buffs.invincible; }
	inline bool IsSlowBuff() const { return m_Buffs.isSlowBuff; };
	inline bool IsMeteorEnhancemen() const { return m_Buffs.meteorEnhancement; };

	void ApplyEffect(const BuffTypeID& buffType);
	void RemoveEffect(const BuffTypeID& buffType);

	BuffTypeID GetActiveAffect() const;

private:
	inline void SetSlowBuff(bool isSlowBuff) { m_Buffs.isSlowBuff = isSlowBuff; };
	inline void SetInvincible(bool isInvincible) { m_Buffs.invincible = isInvincible; }
	inline void SetDoubleScore(bool isDoubleScore) { m_Buffs.doubleScore = isDoubleScore; }
	inline void SetMeteorEnhancement(bool isMeteorEnhancement) { m_Buffs.meteorEnhancement = isMeteorEnhancement; };

	struct Buffs
	{
		bool doubleScore = false;
		bool doubleDamage = false;
		bool invincible = false;
		bool isSlowBuff = false;
		bool meteorEnhancement = false;
	} m_Buffs;
};