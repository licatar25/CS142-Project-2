#ifndef _RosterViewer_
#define _RosterViewer_

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Roster.h"

class RosterViewer
{
public:
	RosterViewer() {}
	void run();//needs to be implemented, please update when implemented
	Roster roster_;
private:
	void execute(const char command, bool& done);
	void display();
	void addplayer();
	//Roster roster_;

	std::string error_message_;

};

void RosterViewer::display() {
		string long_separator(50, '-');

	system("cls"); // clear screen; windows

	if (!error_message_.empty())
	{
		cout << "ERROR: " + error_message_ << endl;
		error_message_.clear();
	}
	else
		cout << "RosterViewer" << endl;

	cout << long_separator << endl
		<< "1. Start a New Season" << endl
		<< "2. Add a player" << endl
		<< "3. Search for a player" << endl
		<< "4. Print a list of players" << endl
		<< "5. Display statistics" << endl
		<< "6. Quit" << endl
		<< long_separator << endl;
}

void RosterViewer::run()
{
	roster_.read_file("Roster.txt");
	bool done = false;
	while (!done) {
		display();
		std::cout << "Command Number: ";
		char command;
		std::cin >> command;
		execute(command, done);
	}

}

void RosterViewer::execute(const char command, bool& done)
{
	switch (command) {
	case '1': {std::cout << "Are you sure that you want to start a new season?(y/n)" << std::endl;//start new season
		char confirm;
		std::cin >> confirm;
		if (confirm == 'y') {
			roster_.clear_roster();
			std::cout << "Please provide a season year: ";
			std::cin >> roster_.season_year_;
		}
		break;
	}
	case '2': {addplayer();//add player
		break;
	}
	case '3': {;//search for player
		break;
	}
	case '4': {std::cout << "Enter the name of the file that you want the roster to be printed to: ";//print to file
		std::string file_name;
		std::cin >> file_name;
		roster_.print_roster(file_name);
		break;
	}
	case '5': {//stats
		std::cout << "--------------------------------------\n\nNumber of Players: " << roster_.roster_size;
		std::cout << "\n\nNumber of Paid Players: " << roster_.count_paid();
		std::cout << "\n\nNumber of Unpaid Players: " << roster_.roster_size - roster_.count_paid();
		std::cout << "\n\n--------------------------------------\n\n";
		break;
	}
	case '6': {//save and quit
		roster_.print_roster("roster.txt");
		done = true;
		break;
	}
	case 'n': { //next player in search view (maybe come up with a different set of chars to choose commands to avoid repeats)

	}
	case 'p': { //previous player in search view

	}
	case 'e': { //edit from within search view

	}
	case 's': { //search from within search view, probably just run the same function as in main

	}
	case ' ': { //print roster within search view
	}
	}
}

void RosterViewer::addplayer() {
	std::string fname;
	std::string lname;
	int yob;
	bool reg_stat;
	std::string registration;
	std::cout << "Please enter the first and last name of the player: ";
	std::cin >> fname >> lname;
	std::cout << "\n\nPlease enter the year of birth of the player: ";
	std::cin >> yob;
	std::cout << "\n\nPlease enter the registration status of the player: ";
	std::cin >> registration;
	if ((registration == "Paid") || (registration == "paid")) reg_stat = true;
	if ((registration == "Unpaid") || (registration == "unpaid")) reg_stat = false;
	roster_.make_player(fname, lname, yob, reg_stat);
}



#endif
