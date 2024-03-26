#pragma once
#include<string>
#include<map>
#include<fstream>
#include "Player.h"
#include<vector>
class CommandInterpreter
{
private:

	std::map<std::string, std::string> Thesaurus;

public:

	CommandInterpreter(std::string Filename = "Thesaurus.txt") { // initialises the thesaurus from a file
		std::string FileText;
		std::ifstream File(Filename);
		while (std::getline(File, FileText)) {
			int x = FileText.find(" ");
			Thesaurus.insert({ FileText.substr(0, x) , FileText.substr(x+1, FileText.length()) });
		}
	}


	std::string SynonymChecker(std::string String); // checks the inputed word against a map of words and outputs the synonym the system recognises

	bool Commander(std::string String, Player* player);

	std::vector<std::string> StringSplit(std::string String,std::string Split);
	
};

