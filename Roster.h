#ifndef _Roster_
#define _Roster_

#include <iostream>
#include <map>
#include <fstream>
#include <string>

#include "Player.h"

using roster_map_ = std::map<std::string, Player>;
class Roster //has the list of players and uses class Player to get info about each player
{
public:
	
	void clear_roster() { roster.clear(); }//to be used for the new season command ---- maybe switch to private eventually?
	inline void make_player(const std::string& fname, const std::string& lname, const int yob, const bool reg_stat); //temporary, maybe
	void print_roster(const bool search, const std::string& file_name);
	void save(const std::string& filename);
	int count_paid();
	int size() { return roster.size(); }
	void read_file(const std::string& filename);
	void set_season_year(int year) { season_year_ = year; }
	void create_search_roster();
	void display_current_player();
	void display_next_player();
	void display_prev_player();
	void update();

private:
	int season_year_; 
	int num_paid;
	roster_map_ roster;
	roster_map_ search_roster;
	void print_cat(const std::string& category, std::ostream& out, Player& player_);
	roster_map_::iterator itr_current_player_;
	int int_current_player_;
};

inline void Roster::make_player(const std::string& fname, const std::string& lname, const int yob, const bool reg_stat)
{
	Player player_(fname, lname, yob, reg_stat, Roster::season_year_);
	std::cout << "Season Year: " << season_year_ << std::endl;
	if ((player_.get_age() >= 4) && (player_.get_age() <= 16))
		roster[lname] = player_;
}
#endif