#ifndef _Player_
#define _Player_
#include <iostream>

#include "Roster.h"
#include "RosterViewer.h"

class Player//contains the actual information of each player
{
public:
	Player() : f_name_("Undefined"),l_name_("Undefined"), yob_(9999),reg_stat_(false) {}
	Player(std::string fname, std::string lname, int yob, bool reg_stat) : 
		f_name_(fname), l_name_(lname), yob_(yob), reg_stat_(reg_stat) {
		age_ = RosterViewer::roster_.get_season_year() - yob_;
		category_ = calc_category();
	}


private:
	std::string calc_category();

	std::string f_name_;
	std::string l_name_;
	int yob_;
	bool reg_stat_;
	const int age_;
	std::string category_;
};

std::string Player::calc_category() {
	
	
};
#endif