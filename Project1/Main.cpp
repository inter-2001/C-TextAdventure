#include <iostream>
#include <vector>
#include <map>
#include "Player.h"
#include "Room.h"
#include "Area.h"
#include "CommandInterpreter.h"

int main() {

	Area StartArea;

	CommandInterpreter Interpreter;

	std::cout << "loading Area... \n";
	StartArea.LoadMapFromFile("Map1.txt");

	// Create a Player
	std::cout << "Creating player... \n";
	Player player("Alice", 100);
	// give them a weapon
	std::cout << "Arming them... \n";
	player.AddWeapon(StartArea.GetWeapon("sword"));
	// Set the player's starting location
	std::cout << "putting them in a room \n";
	player.SetLocation(StartArea.GetRoom("StartRoom"));
	// Game loop (basic interaction)

	bool MainLoop = true;

	while (MainLoop) {
		std::cout << "Current Location: " << player.GetLocation() -> GetDescription() << std::endl;
		try {

			StartArea.EnemyCheck(player.GetLocation());
			std::cout << "\nEnemy Present\n";
		}
		catch(std::exception){}
		std::string choice = " ";
		std::getline(std::cin, choice);
		MainLoop = Interpreter.Commander(choice, &player);
		
	}
	return 0;
}