#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Room.h"
#include "Weapon.h"
#include "Inventory.h"
class Character : public Inventory {
private:
	std::string name;
	int health;
	Weapon* Equiped = nullptr;
public:
	Character(std::string name = "", int health = 0) {
		Character::name = name;
		Character::health = health;
	};
	void TakeDamage(int damage);
	void EquipWeapon(int Iterant);
};


class Player : public Character {
private:
	Room* location;
	std::string description = "";
	
public:
	Player(std::string name, int health) {
		Player::Character(name, health);
		location = nullptr;
	};
	void SetLocation(Room* SetRoom);
	Room* GetLocation();
	void AddDescription(std::string Description);
};
