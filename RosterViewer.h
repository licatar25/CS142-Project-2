#ifndef _RosterViewer_
#define _RosterViewer_

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Roster.h"
#include "Player.h"

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

};

void RosterViewer::display() {
	roster_.display();
}

void RosterViewer::run()
{
	roster_.read_file(filename);
	bool done = false;
	while (!done) {
		display();
		cout << "Command Number: ";
		char command;
		cin >> command;
		execute(command, done);
	}

}

void RosterViewer::execute(const char command, bool& done)
{
	switch (command) {
	case '1': {std::cout << "Are you sure that you want to start a new season?(y/n)" << endl;
		char confirm;
		if (confirm == 'y') {
			roster_.clear_roster();
			std::cout << "Please provide a season year: ";
			cin >> roster_.year;
		}
	}
	case '2': addplayer();
	case '3': 

	}
}

void RosterViewer::addplayer() {
	std::string fname;
	std::string lname;
	int yob;
	bool reg_stat;
	cout << "Please enter the first and last name of the player: ";
	cin >> fname >> lname;
	cout << "\n\nPlease enter the year of birth of the player: ";
	cin >> yob;
	cout << "\n\nPlease enter the registration status of the player: ";
	cin >> reg_stat;
	roster_.make_player(fname, lname, yob, reg_stat);
}



#endif
