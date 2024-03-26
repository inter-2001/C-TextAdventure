#pragma once
#include "Weapon.h"
#include <vector>
class Inventory
{
private:
	std::vector <Weapon*> weapons;
public:
	void AddWeapon(Weapon* WeaponToAdd);
	void RemoveWeapon(Weapon* WeaponToRemove);
	Weapon* GetWeapon(int iter);
	void DisplayWeapons();
	int ReturnSize();
};

