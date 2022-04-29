#ifndef _Roster_
#define _Roster_

#include <iostream>
#include <map>
#include <fstream>
#include <string>

#include "Player.h"
#include "RosterViewer.h"

using roster_map_ = std::map<std::string, Player>;
class Roster //has the list of players and uses class Player to get info about each player
{
public:
	
	void clear_roster() { roster.clear(); }//to be used for the new season command ---- maybe switch to private eventually?
	void display();
	void make_player(const std::string& fname, const std::string& lname, const int yob, const bool reg_stat); //temporary, maybe
	void print_roster(const std::string& file_name);
	int count_paid();
	int roster_size = roster.size();
	int roster_open_size;
	void read_file(const std::string& filename);
private:
	int season_year_; 
	int num_paid;
	roster_map_ roster;
	roster_map_ search_roster;
	void print_cat(const std::string& category, std::ostream& out, Player& player_);
};

void Roster::make_player(const std::string& fname, const std::string& lname, const int yob, const bool reg_stat) {
	Player player_(fname, lname, yob, reg_stat, season_year_);
	if ((player_.get_age() >= 4) && (player_.get_age() <= 16)) roster[lname] = player_;
}

void Roster::display() {

}

void Roster::print_cat(const std::string& category, std::ostream& out, Player& player_) {
	auto itr = roster.begin();
	int count = 0;
	int cat_roster_size; 

	while (itr != roster.end()) {
		player_ = itr->second;
		if (player_.get_cat() == category) ++cat_roster_size;
	}

	while (itr != roster.end()) {
		player_ = itr->second;
		if (player_.get_cat() == category) {
			out << "Player " << count << "/" << cat_roster_size << std::endl;
			out << "--------------------------------------\n";
			out << player_.get_lname() << ',' << player_.get_fname() << std::endl;
			out << player_.get_yob() << std::endl << player_.get_cat() << std::endl << player_.get_regstat() << std::endl;
			out << "--------------------------------------\n\n";
			count++;
		}
		++itr;
	}
}

void Roster::print_roster(const std::string& file_name) {
	std::ofstream out(file_name);
	Player player_;
	auto itr = roster.begin();
	int count = 0;
	int roster_size = roster.size();
	int s_roster_size = search_roster.size();
	if (true) {//in main view(true is a placeholder to prevent compiling/autocorrect errors
		print_cat("U17",out,player_);
		print_cat("U14", out, player_);
		print_cat("U12", out, player_);
		print_cat("U10", out, player_);
		print_cat("U8", out, player_);
		print_cat("U6", out, player_);
	}
	else {//in search view
		while (itr != search_roster.end()) {
			player_ = itr->second;
			out << "Player " << count << "/" << s_roster_size << std::endl;
			out << "--------------------------------------\n";
			out << player_.get_lname() << ',' << player_.get_fname() << std::endl;
			out << player_.get_yob() << std::endl << player_.get_cat() << std::endl << player_.get_regstat() << std::endl;
			out << "--------------------------------------\n\n";
			count++;
			++itr;
		}
	}
}

int Roster::count_paid() {
	Player player_;
	auto itr = roster.begin();
	while (itr != roster.end()) {
		player_ = itr -> second;
		if (player_.get_regstat() == true) ++num_paid;
	}
	return num_paid;
}

void Roster::read_file(const std::string& filename) {
	std::ifstream in(filename);
	std::string dummy;//<-----------------------------best way is probably not to add dummy
	int idummy;
	std::string fname;
	std::string lname;
	int yob;
	bool reg_stat;
	in >> dummy >> idummy;
	in.ignore();
	in >> roster_open_size;
	in.ignore();
	getline(in, dummy);
	in >> lname;
	in.ignore();
	in >> fname;
	in.ignore();
	in >> yob;
	in.ignore();
	std::getline(in, dummy);
	in >> reg_stat;
	in.ignore();
	std::getline(in, dummy);
	in.ignore();
	for (int i = 0; i < roster_open_size; ++i) {
		std::getline(in, dummy);
		std::getline(in, dummy);
		in >> lname;
		in.ignore();
		in >> fname;
		in.ignore();
		in >> yob;
		in.ignore();
		std::getline(in, dummy);
		in >> reg_stat;
		in.ignore();
		std::getline(in, dummy);
		in.ignore();
	}

}
#endif