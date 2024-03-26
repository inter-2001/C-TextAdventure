#pragma once
#include <string>
class Weapon
{
private:
	std::string name;
	std::string description;
	int attack;
	int defense;
public:
	Weapon(std::string name = "", std::string description = "",int attack = 0, int defense = 0) {
		Weapon::name = name;
		Weapon::description = description;
		Weapon::attack = attack;
		Weapon::defense = defense;
	}
	std::string GetName();
	std::string GetDescription();
	int GetAttack();
	int GetDefense();
};

