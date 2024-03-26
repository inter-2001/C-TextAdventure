#include "Player.h"

void Character::TakeDamage(int damage)
{
	try {
		health -= (damage - Equiped->GetDefense());
	}
	catch (std::exception) {
		health -= (damage);
	}
}

void Character::EquipWeapon(int Iterant)
{
	Equiped = GetWeapon(Iterant);
}

void Player::SetLocation(Room* SetRoom)
{
	location = SetRoom;
}

Room* Player::GetLocation()
{
	return(location);
}

void Player::AddDescription(std::string Description)
{
	description = Description;
}
