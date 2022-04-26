#ifndef _Player_
#define _Player_
#include <iostream>

#include "Roster.h"
#include "RosterViewer.h"

class Player//contains the actual information of each player
{
public:
	Player() : f_name_("Undefined"),l_name_("Undefined"), {}

private:
	std::string f_name_;
	std::string l_name_;
	int yob_;
	bool reg_stat_;
	int age_;
	std::string category_;
};


#endif