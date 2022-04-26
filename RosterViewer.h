#ifndef _RosterViewer_
#define _RosterViewer_

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Roster.h"
#include "Player.h"

class RosterViewer
{
public:
	RosterViewer() {}
	void run();//needs to be implemented, please update when implemented

private:
	void execute(char command, bool& done);
	
	Roster roster_;

};

void RosterViewer::run()
{
	roster_.read_file();


}

void RosterViewer::execute(char command, bool& done)
{
	switch()
}





#endif
