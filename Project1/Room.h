#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>


class Room
{
public:
	enum Cardinals // sets the cardinal directions as enum
	{ 
		north, east, south, west , error
	};
	static Cardinals Opposate(Cardinals Direction){
		switch (Direction) {
		case north:
			return(south);
		case south:
			return(north);
		case east:
			return(west);
		case west:
			return(east);
		}
	}
private:  

	std::string description;
	std::map <Cardinals, Room*> exits;
	
public:
	Room(const std::string &desc)
	{
		description = desc;
	}

	void AddExit(Cardinals Direction, Room* destination);

	std::string GetDescription();

	Room* GetExit(Cardinals Direction);

	void SetDescription(std::string Desk);

};

