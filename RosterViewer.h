#ifndef _RosterViewer_
#define _RosterViewer_

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Roster.h"

class RosterViewer
{
public:
	RosterViewer() {}
	void run();//needs to be implemented, please update when implemented

private:
	void execute(const char command, bool& done);
	void display();
	void display_menu();
	void display_search();
	void add_player();
	void search();
	
	
	Roster roster_;
	bool search_;
	std::string error_message_;


};
#endif
