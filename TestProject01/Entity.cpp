#include <iostream>
#include <string>
#include "Entity.hpp"


//	Constructors:


Entity::Entity()
{
	healthComponent = HealthComponent();
	name = "New Entity";
	transform = Transform(Vector2(0.0f,0.0f));
}

Entity::Entity(int maxHp, std::string name, Vector2 position)
{
	healthComponent = HealthComponent(maxHp);
	this->name = name;
	transform = Transform(position);
}

Monster::Monster()
{
	strength = 10.0f;
}

Monster::Monster(int maxHp, std::string name, Vector2 position, float strength) : Entity(maxHp, name, position)
{
	this->strength = strength;
}

Robot::Robot()
{
	ammo = 10;
	bulletDamage = 35.0f;
}

Robot::Robot(int maxHp, std::string name, Vector2 position, int ammo, float bulletDamage) : Entity(maxHp, name, position)
{
	this->ammo = ammo;
	this->bulletDamage = bulletDamage;
}

Cyborg::Cyborg()
{
	modelName = "iCyborg 2600";
}

Cyborg::Cyborg(int maxHp, std::string name, Vector2 position, float strength, int ammo, float bulletDamage, std::string modelName) : Robot(maxHp, name, position, ammo, bulletDamage), Monster(maxHp, name, position, strength), Entity(maxHp, name, position)
{
	this->modelName = modelName;
}


//	Getters, setters:


float Monster::GetStrength()
{
	return strength;
}

int Robot::GetAmmo()
{
	return ammo;
}

float Robot::GetBulletDamage()
{
	return bulletDamage;
}

void Robot::SetAmmo(int value)
{
	ammo = value;
}

std::string Cyborg::GetModelName()
{
	return modelName;
}


//	Methods:


/// <summary>
/// Displays all important information about the Entity in the console.
/// </summary>
void Entity::ShowInformation()
{
	std::string lifeStateString[3] = { "Healthy", "Wounded", "Dead" };
	std::cout << "\nEntity information: \n\nHp: " + std::to_string(healthComponent.GetHp()) + "/" + std::to_string(healthComponent.GetMaxHp()) + ",\nLife State: " + lifeStateString[healthComponent.GetLifeState()] + "\nName: " + name + "\nPosition: " + std::to_string(transform.position.x) + ", " + std::to_string(transform.position.y) + "\n";
}

/// <summary>
/// Attacks other entity, dealing damage in the process.
/// </summary>
/// <param name="attackedEntity"></param>
void Monster::MeleeAttack(Entity &attackedEntity)
{
	attackedEntity.healthComponent.DecreaseHp(strength);
}

/// <summary>
/// Displays all important information about the Monster in the console.
/// </summary>
void Monster::ShowInformation()
{
	std::string lifeStateString[3] = { "Healthy", "Wounded", "Dead" };
	std::cout << "\nMonster information: \n\nHp: " + std::to_string(healthComponent.GetHp()) + "/" + std::to_string(healthComponent.GetMaxHp()) + ",\nLife State: " + lifeStateString[healthComponent.GetLifeState()] + "\nStrength: " + std::to_string(strength) + "\nName: " + name + "\nPosition: " + std::to_string(transform.position.x) + ", " + std::to_string(transform.position.y) + "\n";
}


/// <summary>
/// Attacks other entity, dealing damage and using up ammo in the process.
/// </summary>
void Robot::RangedAttack(Entity &attackedEntity)
{
	if (ammo > 0)
	{
		ammo--;
		attackedEntity.healthComponent.DecreaseHp(bulletDamage);
	}
}

/// <summary>
/// Displays all important information about the Robot in the console.
/// </summary>
void Robot::ShowInformation()
{
	std::string lifeStateString[3] = { "Healthy", "Wounded", "Dead" };
	std::cout << "\nRobot information: \n\nHp: " + std::to_string(healthComponent.GetHp()) + "/" + std::to_string(healthComponent.GetMaxHp()) + ",\nLife State: " + lifeStateString[healthComponent.GetLifeState()] + "\nAmmo: " + std::to_string(ammo) + "\nBullet Damage: " + std::to_string(bulletDamage) + "\nName: " + name + "\nPosition: " + std::to_string(transform.position.x) + ", " + std::to_string(transform.position.y) + "\n";
}

void Cyborg::DoubleAttack(Entity& attackedEntity)
{
	MeleeAttack(attackedEntity);
	RangedAttack(attackedEntity);
}

/// <summary>
/// Displays all important information about the Cyborg in the console.
/// </summary>
void Cyborg::ShowInformation()
{
	std::string lifeStateString[3] = { "Healthy", "Wounded", "Dead" };
	std::cout << "\nCyborg information: \n\nHp: " + std::to_string(healthComponent.GetHp()) + "/" + std::to_string(healthComponent.GetMaxHp()) + ",\nLife State: " + lifeStateString[healthComponent.GetLifeState()] + "\nStrength: " + std::to_string(strength) + "\nAmmo: " + std::to_string(ammo) + "\nBullet Damage: " + std::to_string(bulletDamage) + "\nModel Name: " + modelName + "\nName: " + name + "\nPosition: " + std::to_string(transform.position.x) + ", " + std::to_string(transform.position.y) + "\n";
}