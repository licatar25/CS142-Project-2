#include "RosterViewer.h"
using namespace std;

void RosterViewer::display() {
	system("cls"); // clear screen; windows

	if (!error_message_.empty())
	{
		cout << "ERROR: " + error_message_ << endl;
		error_message_.clear();
	}
	else
		cout << "RosterViewer" << endl;

	if (!search_)
		display_menu();
	else
		display_search();
}

void RosterViewer::display_menu()
{
	string long_separator(50, '-');

	cout << "Main Menu" << endl
		<< long_separator << endl
		<< "1. Start a New Season" << endl
		<< "2. Add a player" << endl
		<< "3. Search for a player" << endl
		<< "4. Print a list of players" << endl
		<< "5. Display statistics" << endl
		<< "6. Quit" << endl
		<< long_separator << endl;
}

void RosterViewer::display_search()
{
	string long_separator(50, '-');
	cout << "Search View" << endl
		<< long_separator << endl;
	roster_.display_current_player();
	cout << long_separator << endl
		<< "| 1. Next   | 2. Previous | 3. Edit |" << endl
		<< "| 4. Search | 5. Print    | 6. Exit |" << endl;
}

void RosterViewer::run()
{
	roster_.read_file("Roster.txt");
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
	
	if (!search_) {
		switch (command) {
		case '1': {cout << "Are you sure that you want to start a new season? (y/n) ";//start new season
			char confirm;
			cin >> confirm;
			if (confirm == 'y') {
				roster_.clear_roster();
				cout << "Please provide a season year: ";
				int year = 0;
				cin >> year;
				roster_.set_season_year(year);
			}
			break;
		}
		case '2': {
			add_player();//add player
			break;
		}
		case '3': {
			cin.ignore();
			search();
			break;
		}
		case '4': {
			cout << "Enter the name of the file that you want the roster to be printed to: ";//print to file
			string file_name;
			cin >> file_name;
			roster_.print_roster(search_, file_name);
			break;
		}
		case '5': {//stats
			cout << "--------------------------------------\n\nNumber of Players: " << roster_.size();
			cout << "\n\nNumber of Paid Players: " << roster_.count_paid();
			cout << "\n\nNumber of Unpaid Players: " << roster_.size() - roster_.count_paid();
			cout << "\n\n--------------------------------------\n\n";
			break;
		}
		case '6': {//save and quit
			roster_.save("Roster.txt");
			done = true;
			break;
		}
		default: {
			error_message_ = "Please enter one of the command numbers listed below.";
		}
		}
	}
	else if (search_)
		switch (command) {
		case '1': {
			roster_.display_next_player();
			break;
		}
		case '2': {
			roster_.display_prev_player();
			break;
		}
		case '3': {
			roster_.update();
			break;
		}
		case '4': {
			cin.ignore();
			search();
			break;
		}
		case '5': {
			cout << "Enter the name of the file that you want the roster to be printed to: ";//print to file
			string file_name;
			cin >> file_name;
			roster_.print_roster(search_, file_name);
			break;
		}
		case '6': {
			search_ = false;
			break;
		}
		}
}

void RosterViewer::add_player() {
	string fname;
	string lname;
	int yob;
	bool reg_stat;
	string registration;
	cout << "Please enter the first and last name of the player: ";
	cin >> fname >> lname;
	cout << "\n\nPlease enter the year of birth of the player: ";
	cin >> yob;
	cout << "\n\nPlease enter the registration status of the player: ";
	cin >> registration;
	if ((registration == "Paid") || (registration == "paid")) reg_stat = true;
	if ((registration == "Unpaid") || (registration == "unpaid")) reg_stat = false;
	roster_.make_player(fname, lname, yob, reg_stat);
}

void RosterViewer::search()
{
	search_ = true;
	roster_.create_search_roster();
}