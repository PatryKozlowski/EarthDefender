#include "Affect.hpp"

void Affect::ApplyEffect(const BuffTypeID& buffType)
{
	switch (buffType)
	{
	case BuffTypeID::DOUBLE_DAMAGE:
		SetDoubleDamage(true);
		break;

	case BuffTypeID::DOUBLE_SCORE:
		SetDoubleScore(true);
		break;

	case BuffTypeID::INVINCIBILITY:
		SetInvincible(true);
		break;

	case BuffTypeID::SLOW_METEOR_SPEED:
		SetSlowBuff(true);
		break;

	case BuffTypeID::BOSS_METEOR_ENHANCEMENT:
		SetMeteorEnhancement(true);
		break;

	default:
		break;
	}
}

void Affect::RemoveEffect(const BuffTypeID& buffType)
{
	switch (buffType)
	{
	case BuffTypeID::DOUBLE_DAMAGE:
		SetDoubleDamage(false);
		break;

	case BuffTypeID::DOUBLE_SCORE:
		SetDoubleScore(false);
		break;

	case BuffTypeID::INVINCIBILITY:
		SetInvincible(false);
		break;

	case BuffTypeID::SLOW_METEOR_SPEED:
		SetSlowBuff(false);
		break;

	case BuffTypeID::BOSS_METEOR_ENHANCEMENT:
		SetMeteorEnhancement(false);
		break;

	default:
		break;
	}
}

BuffTypeID Affect::GetActiveAffect() const
{
	if (IsDoubleScore())
	{
		return BuffTypeID::DOUBLE_SCORE;
	}
	else if (IsDoubleDamage())
	{
		return BuffTypeID::DOUBLE_DAMAGE;
	}
	else if (IsInvincible())
	{
		return BuffTypeID::INVINCIBILITY;
	}
	else if (IsSlowBuff())
	{
		return BuffTypeID::SLOW_METEOR_SPEED;
	}
	else if (IsMeteorEnhancemen())
	{
		return BuffTypeID::BOSS_METEOR_ENHANCEMENT;
	}

	return BuffTypeID::NONE;
}
