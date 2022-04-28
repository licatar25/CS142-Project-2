#ifndef _Roster_
#define _Roster_

#include <iostream>
#include <map>
#include <fstream>

#include "Player.h"
#include "RosterViewer.h"

using roster_map_ = std::map<std::string, Player>;
class Roster //has the list of players and uses class Player to get info about each player
{
public:
	
	void clear_roster() { roster.clear(); }//to be used for the new season command ---- maybe switch to private eventually?
	void display();
	void make_player(std::string fname, std::string lname, int yob, std::string reg_stat); //temporary, maybe
	void print_roster(const std::string& file_name);
private:
	int season_year_;
	Player player_;
	roster_map_ roster;
	roster_map_ search_roster;
};

void Roster::make_player(std::string fname, std::string lname, int yob, std::string reg_stat) {
	player_(fname, lname, yob, reg_stat, season_year_);
	if ((player_.age_ >= 6) && (player_.age_ <= 16)) roster[lname] = player_;
}

void Roster::display() {

}

void Roster::print_roster(const std::string& file_name) {
	std::ofstream out(file_name);
	auto itr = roster.begin();
	if (true) {//in main view(true is a placeholder to prevent compiling/autocorrect errors
		while (itr != roster.end()) {
			itr -> second = player_;
			out << player_.l_name_ << ", " << player_.f_name_ << std::endl;

		}
	}
}
#endif