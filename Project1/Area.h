#pragma once
#include "Room.h"
#include "Weapon.h"
#include "Player.h"

class Area
{
public:
	Area(std::string name = "", std::string description = "", std::map<std::string, Room> Rooms = {})
	{
		Area::Rooms = Rooms;
		Area::name = name;
		Area::description = description;
	}
private:
	std::string name;
	std::string description;
	std::map<std::string, Room> Rooms;
	std::map<std::string, Weapon> Weapons;
	std::map<Room*, Player> Enemies;

	

public:
	void AddRoom(std::string name = "", Room room = { "" });

	Room* GetRoom(std::string Room);

	Weapon* GetWeapon(std::string Weapon);

	void AddConnection(std::string From, Room::Cardinals Direction, std::string Too);

	void LoadMapFromFile(std::string Filename);

	Player EnemyCheck(Room* RoomToCheck);

	void PrintMap();

};

