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
	int count_paid() {};
	int roster_size = roster.size();
	void read_file(std::string filename);
private:
	int season_year_; 
	int num_paid;
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
	int count = 0;
	int roster_size = roster.size();
	int s_roster_size = search_roster.size();
	if (true) {//in main view(true is a placeholder to prevent compiling/autocorrect errors
		while (itr != roster.end()) {
			itr -> second = player_;
			out << "Player " << count << "/" << roster_size << std::endl;
			out << "--------------------------------------\n";
			out << player_.l_name_ << ", " << player_.f_name_ << std::endl;
			out << player_.yob_ << std::endl << player_.category_ << std::endl << player_.reg_stat_ << std::endl;
			out << "--------------------------------------\n\n";
			count++;
			++itr;
		}
	}
	else {//in search view
		while (itr != search_roster.end()) {
			itr->second = player_;
			out << "Player " << count << "/" << s_roster_size << std::endl;
			out << "--------------------------------------\n";
			out << player_.l_name_ << ", " << player_.f_name_ << std::endl;
			out << player_.yob_ << std::endl << player_.category_ << std::endl << player_.reg_stat_ << std::endl;
			out << "--------------------------------------\n\n";
			count++;
			++itr;
		}
	}
}

int Roster::count_paid() {
	auto itr = roster.begin();
	while (itr != roster.end()) {
		itr -> second = player_;
		if (player_.reg_stat_ == true) ++num_paid;
	}
	return num_paid;
}

void Roster::read_file(std::string filename) {
	std::ifstream in(filename);
	std::string dummy;//<-----------------------------best way is probably not to add dummy
	std::string fname;
	std::string lname;
	int yob;
	bool reg_stat;
	getline(in, dummy);


}
#endif