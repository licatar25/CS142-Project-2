#include <iostream>
#include "Roster.h"

	int num_entries = 0;
	in >> num_entries;
	in >> season_year_;

	string lname, fname;
	int yob = 0;
	bool regstat;
	for (int i = 0; i < num_entries; ++i)
	{
		in >> lname >> fname >> regstat >> yob;
		Player player(fname, lname, yob, regstat, season_year_);
		roster[lname] = player;
	}
}

void Roster::save(const string& filename)
{
	ofstream out(filename);

	out << roster.size() << ' ' << season_year_ << endl;
	for (auto itr = roster.begin(); itr != roster.end(); ++itr)
	{
		Player player = itr->second;
		out << player.get_lname() << ' ' << player.get_fname() << endl;
		out << player.get_regstat() << ' ' << player.get_yob() << endl;
	}
	out.close();
}

void Roster::create_search_roster()
{

	cout << "Please enter known information about player." << endl
		<< "If unkown leave field blank.";
	cout << "First Name: ";


}