#pragma once
#include <iostream>
#include "HealthComponent.hpp"
#include "Transform.hpp"

class Entity
{
public:

	Transform transform;
	HealthComponent healthComponent;
	std::string name;

	Entity();
	Entity(int maxHp, std::string name, Vector2 position);
	virtual void ShowInformation();

};

class Monster : public virtual Entity
{
protected:

	float strength;

public:

	Monster();
	Monster(int maxHp, std::string name, Vector2 position, float strength);

	float GetStrength();

	void MeleeAttack(Entity &attackedEntity);
	virtual void ShowInformation();

};

class Robot : public virtual Entity
{
protected:

	int ammo;
	float bulletDamage;

public:

	Robot();
	Robot(int maxHp, std::string name, Vector2 position, int ammo, float bulletDamage);

	int GetAmmo();
	float GetBulletDamage();

	void SetAmmo(int value);
	
	void RangedAttack(Entity& attackedEntity);
	virtual void ShowInformation();

};

class Cyborg : public Monster, public Robot
{
protected:

	std::string modelName;

public:

	Cyborg();
	Cyborg(int maxHp, std::string name, Vector2 position, float strength, int ammo, float bulletDamage, std::string modelName);

	std::string GetModelName();

	void DoubleAttack(Entity& attackedEntity);
	void ShowInformation();
};