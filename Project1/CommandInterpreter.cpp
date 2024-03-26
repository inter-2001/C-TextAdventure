#include "CommandInterpreter.h"

std::string CommandInterpreter::SynonymChecker(std::string String) // takes a word and returns a synonym the system understands
{
	
	for (int i = 0; i < String.length()-1; i++) { // transfers the sting to lower case
		String[i] = std::tolower(String[i]); 
	}
	std::string result = ""; // initialise the result
	try { // try to find the word in the thesaurus
		
		result = Thesaurus.at(String);
		return (result); // return the understandable word
	}
	catch (std::exception) { // if the word isnt in there return an error
		return("Error");
	}
	
}


bool CommandInterpreter::Commander(std::string String, Player* player) // takes a command string and player and attempts to do the command on the player
{
	std::vector<std::string> CommandStrings = StringSplit(String," "); // splits the string into indavidual words

	for (int i = 0; i < CommandStrings.size(); i++) {
		std::string Command = "Error"; // sets the command by default to do nothing
		try {

			Command = SynonymChecker(CommandStrings[i]);
		}
		catch (std::exception) { std::cout << "error2\n"; }

			if (Command == "Error") {  }

// ----------------------------------------------------------------Directional Commands---------------------------------------------------------------- //

			else if ((Command == "north") || (Command == "south") || (Command == "east") || (Command == "west")) { // if the command is directional
				
				Room::Cardinals CardDirection = Room::north; // transforms the command into an enum

				if (Command == "north") {
					CardDirection = Room::north;
				}
				else if (Command == "south") {
					CardDirection = Room::south;
				}
				else if (Command == "east") {
					CardDirection = Room::east;
				}
				else if (Command == "west") {
					CardDirection = Room::west;
				}
				else
				{
					CardDirection = Room::error;
				}


				Room* nextRoom = player->GetLocation()->GetExit(CardDirection); // sets the next rooms value
				
				if (nextRoom != nullptr){ // if the next room is valid then send the pla
					player->SetLocation(nextRoom);
					std::cout << "You move to the next room." << std::endl;
				}
				
				else {
					std::cout << "You can't go that way." << std::endl;
				}
			}

// ----------------------------------------------------------------Interaction Commands---------------------------------------------------------------- //
			else if (Command == "weaponcheck") { // weapon management system
				std::string SubCommand = "0";
				while (SubCommand != "3") {
					std::cout << "\nYou Can: \n1. View Weapons\n2.Change Weapon\n3. Exit\n> ";
					std::cin >> SubCommand;

					if (SubCommand == "1") { player->DisplayWeapons(); }
					else if (SubCommand == "2") { 
					
						std::cout << "\nwhich weapon? (as a number from 0)\n> ";
						std::string SubSubCommand;
						std::cin >> SubSubCommand;

						try {
							int Intified = std::stoi(SubSubCommand);
							if (Intified < player->ReturnSize()) {
								player->EquipWeapon(Intified);
							}
							else {
								std::cout << "\nNot a valid weapon\n";
							}
						}
						catch (std::exception) {
							std::cout << "\nNot a valid weapon\n";
						}
					}

				}
			}
			
			else if (Command == "exit") {
				return(false);
			}
			else if (Command == "look") {
				std::cout << "you see " << player->GetLocation()->GetDescription() << "\n";
			}
		
	}

	return(true);
}

std::vector<std::string> CommandInterpreter::StringSplit(std::string String,std::string Split) // function to split a sentance into words
{
	int StrPos = 0;
	std::string SubString;
	std::vector<std::string> Output;

	while ((StrPos = String.find(Split)) != std::string::npos) { // untill the next split istn found
		SubString = String.substr(0, StrPos);
		Output.push_back(SubString);
		String.erase(0, StrPos + Split.length());
	}
	Output.push_back(String); // add on the last string to the end

	return (Output);
}
