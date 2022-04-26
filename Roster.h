#ifndef _Roster_
#define _Roster_
#include <iostream>
#include <map>
#include "Player.h"

using roster_map_ = std::map<std::string, Player>;
class Roster //has the list of players and uses class Player to get info about each player
{
public:

	void clear_roster() { roster.clear(); }//to be used for the new season command
	void run();//needs to be implemented, please update when implemented
private:

	roster_map_ roster;
};

#endif