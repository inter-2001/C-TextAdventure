#include "Area.h"
#include "Room.h"
#include <fstream>

Room* Area::GetRoom(std::string room)
{
	Room* retRoom = &Rooms.find(room)->second;
	return(retRoom);
}

void Area::AddRoom(std::string name, Room room) {
	Rooms.insert({ name,room });
}


void Area::AddConnection(std::string From, Room::Cardinals Direction, std::string Too)
{
	GetRoom(From)->AddExit(Direction, GetRoom(Too)); // add the new connection
}





void Area::PrintMap() {

	for (auto i = Rooms.begin(); i != Rooms.end(); i++) {
		std::cout << i->second.GetDescription() << "\n";
	}

}


void Area::LoadMapFromFile(std::string Filename)
{
	std::string FileText;
	std::ifstream File(Filename);

	bool isRoom = false;
	bool isItem = false;


	while (std::getline(File, FileText)){
// ---------------------------------------- Item Code ------------------------------------------ //
		
		if (FileText == "<Items>") {
			std::cout << "Loading Items \n";
		// item options
			std::getline(File, FileText);

			while (FileText != "</Items>") {
				// weapons

				if (FileText == "<weapon>") {
					
					// get all the values for the weapon to be added to the master list

					std::getline(File, FileText);
					std::string TempName = FileText;

					std::getline(File, FileText);
					std::string TempDesc = FileText;

					std::getline(File, FileText);
					int TempDam = std::stoi(FileText);

					std::getline(File, FileText);
					int TempDef = std::stoi(FileText);

					Weapons.insert({ TempName,{TempName,TempDesc,TempDam,TempDef} });
				}



				std::getline(File, FileText);
			}
		}

// ---------------------------------------- Room base code --------------------------------------- //
		
		if (FileText == "<Room>") {
			std::cout << "loading Room... \n";
			std::getline(File, FileText); // retreve name
			std::string TempName = FileText;

			std::getline(File, FileText); // retreve description
			std::string TempDesc = FileText;

			Room TempRoom(TempDesc);

			while (FileText != "</Room>") {
			
				std::getline(File, FileText);
			} // end while
			AddRoom(TempName,TempRoom);
		}

// --------------------------------------- Enemy code --------------------------------------- //

		if (FileText == "<Enemy>") {
			std::cout << "Loading Enemy... \n";
			std::getline(File, FileText);
			std::string TempEnName = FileText;

			std::getline(File, FileText);
			std::string TempEnDesc = FileText;

			std::getline(File, FileText);
			std::string TempWeap = FileText;

			std::getline(File, FileText);
			int TempHealth = std::stoi(FileText);

			std::getline(File, FileText);
			std::string TempRoom = FileText;

			Enemies.insert({ GetRoom(TempRoom),{TempEnName,TempHealth} });

			Enemies.at(GetRoom(TempRoom)).AddWeapon(GetWeapon(TempWeap)); //adds the enemies weapon
			Enemies.at(GetRoom(TempRoom)).AddDescription(TempEnDesc); //adds the enemies weapon

		}
// --------------------------------------- Connection Code --------------------------------------- //
		if (FileText == "<Connection>") {
			std::cout << "Loading Connection... \n";
		
			std::getline(File, FileText); // retreve Room 1
			std::string From = FileText;

			std::getline(File, FileText); // retreve Room 1
			std::string Direction = FileText;

			std::getline(File, FileText); // retreve Room 2
			std::string Too = FileText;


			// Direction mapping
			Room::Cardinals MapDirection = Room::north;
			if (Direction == "North"){
				MapDirection = Room::north;
			}

			if (Direction == "South") {
				MapDirection = Room::south;
			}

			if (Direction == "East") {
				MapDirection = Room::east;
			}

			if (Direction == "West") {
				MapDirection = Room::west;
			}
			 

			std::getline(File, FileText); // retreve the next line
			// options for connections
			bool TwoWay = false;

			while (FileText != "</Connection>") {
				if (FileText == "TwoWay") {
					TwoWay = true;
				}

				std::getline(File, FileText); // retreve the next line

			}
			
			std::cout << From << Too << "\n";

			AddConnection(From, MapDirection, Too);
			if (TwoWay){ AddConnection(Too, Room::Opposate(MapDirection), From); }
			
		
		}


	}
}

// weapon retreval from central list

Weapon* Area::GetWeapon(std::string Weapon)
{
	return (&Weapons.at(Weapon));
}


Player Area::EnemyCheck(Room* RoomToCheck) {
	return(Enemies.at(RoomToCheck));
};
