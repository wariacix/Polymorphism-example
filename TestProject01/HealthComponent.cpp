#include <iostream>
#include "HealthComponent.hpp"


//	Constructors:


/// <summary>
/// Initializes the HealthComponent object with a base maxHp of 100.
/// </summary>
HealthComponent::HealthComponent()
{
	lifeState = Healthy;
	maxHp = 100;
	hp = maxHp;
}

/// <summary>
/// Initializes the HealthComponent object based on value provided.
/// </summary>
/// <param name="value">- Sets the MaxHp and Hp parameters</param>
HealthComponent::HealthComponent(int value)
{
	if (value < 1) std::cout << "ERR1: Wrong value in HealthComponent's constructor";
	lifeState = Healthy;
	maxHp = value;
	hp = maxHp;
}


//	Getters, setters:


int HealthComponent::GetHp()
{
	return hp;
}

int HealthComponent::GetMaxHp()
{
	return maxHp;
}

LifeState HealthComponent::GetLifeState()
{
	return lifeState;
}

void HealthComponent::SetMaxHp(int value)
{
	maxHp = value;
}


//	Methods:


/// <summary>
/// Increases the hp and sets the appropriate lifeState value.
/// </summary>
/// <param name="value">- added hp</param>
void HealthComponent::IncreaseHp(int value)
{
	hp += value;

	if (hp > maxHp)
	{
		lifeState = Healthy;
		hp = maxHp;
	}
}

/// <summary>
/// Decreases the hp and sets the appropriate lifeState value.
/// </summary>
/// <param name="value">- decreased hp</param>
void HealthComponent::DecreaseHp(int value)
{
	hp -= value;
	if (hp <= 0)
	{
		lifeState = Dead;
		hp = 0;
	}
	else
	{
		lifeState = Wounded;
	}
}

void HealthComponent::Kill()
{
	DecreaseHp(maxHp);
}