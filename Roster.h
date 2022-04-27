#ifndef _Roster_
#define _Roster_

#include <iostream>
#include <map>

#include "Player.h"
#include "RosterViewer.h"

using roster_map_ = std::map<std::string, Player>;
class Roster //has the list of players and uses class Player to get info about each player
{
public:
	
	void clear_roster() { roster.clear(); }//to be used for the new season command ---- maybe switch to private eventually?

	void make_player(); //temporary, maybe
private:
	int season_year_;
	Player player_;
	roster_map_ roster;
};

void Roster::make_player() {
	std::string fname;
	std::string lname;
	int yob;
	bool reg_stat;
	std::cin >> lname >> fname >> yob >> reg_stat;
	player_(fname, lname, yob, reg_stat, season_year_);
	if ((player_.age_ >= 6) && (player_.age_ <= 16)) roster[lname] = player_;
}
#endif