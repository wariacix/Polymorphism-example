#pragma once
#include <iostream>

enum LifeState
{
	Healthy,
	Wounded,
	Dead
};

class HealthComponent
{
private:

	LifeState lifeState;
	int hp, maxHp;

public:

	HealthComponent();
	HealthComponent(int maxHp);

	int GetHp();
	int GetMaxHp();
	LifeState GetLifeState();

	void SetMaxHp(int value);

	void IncreaseHp(int value);
	void DecreaseHp(int value);
	void Kill();
};