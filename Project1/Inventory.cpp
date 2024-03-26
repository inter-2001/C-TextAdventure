#include "Inventory.h"
#include <iostream>

void Inventory::AddWeapon(Weapon* WeaponToAdd)
{
	weapons.push_back(WeaponToAdd);
}

void Inventory::RemoveWeapon(Weapon* WeaponToRemove)
{
	for (auto i = weapons.begin(); i <= weapons.end();i++) { // iterate through inventoru
		if (*i == WeaponToRemove) { // if the inventory element is to be removed
			weapons.erase(i); // erase it
			break; // break so that no dupicates are destroied
		}
	}
}

Weapon* Inventory::GetWeapon(int iter)
{
	return weapons[iter];
}

void Inventory::DisplayWeapons()
{
	std::cout << "\nWeapons Availible";
	for (int i = 0; i < weapons.size();i++) { // iterate through inventoru

		std::cout << "\nName:" << weapons[i]->GetName() << "\nDescription: " << weapons[i]->GetDescription() << "\n";

	}
}

int Inventory::ReturnSize()
{
	return weapons.size();
}
