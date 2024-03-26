#include "Room.h"


void Room::AddExit(Cardinals Direction,Room* destination)
{	
	try { // try and check if the direction exitst, if it doesnt it will return an exception and shunt into the exception
		if (exits.at(Direction) != nullptr) {
			std::cout << "Error: Direction allready exists\n";
			return;
		}
	}
	catch(std::exception){
		exits.insert({Direction,destination});
	}
}

std::string Room::GetDescription()
{
	return std::string(description);
}



Room* Room::GetExit(Cardinals Direction)
{
	try {
		switch (Direction)  // returns the room at the specified exit
		{
			case north:

				return(exits.at(north));
			case south:
				return(exits.at(south));
			case east:
				return(exits.at(east));
			case west:
				return(exits.at(west));
			default:
				return(nullptr);
		}
	}
	catch (std::exception) {
		return(nullptr);
	}
}

void Room::SetDescription(std::string Desk)
{
	Room::description = Desk;
}

