#include "Roster.h"
using namespace std;

void Roster::print_cat(const string& category, ostream& out, Player& player_) {
	auto itr = roster.begin();
	int count = 0;
	int cat_roster_size = 0;

	while (itr != roster.end()) {
		player_ = itr->second;
		if (player_.get_cat() == category) ++cat_roster_size;
		++itr;
	}

	itr = roster.begin();
	while (itr != roster.end()) {
		player_ = itr->second;
		if (player_.get_cat() == category) {
			out << "Player " << count << "/" << cat_roster_size << endl;
			out << "--------------------------------------\n";
			out << player_.get_lname() << ',' << player_.get_fname() << endl;
			out << player_.get_yob() << endl << player_.get_cat() << endl << player_.get_regstat() << endl;
			out << "--------------------------------------\n\n";
			count++;
		}
		++itr;
	}
}

void Roster::print_roster(const string& file_name) {
	ofstream out(file_name);
	Player player_;
	auto itr = roster.begin();
	int count = 0;
	int s_roster_size = search_roster.size();
	if (true) {//in main view(true is a placeholder to prevent compiling/autocorrect errors
		print_cat("U17", out, player_);
		print_cat("U14", out, player_);
		print_cat("U12", out, player_);
		print_cat("U10", out, player_);
		print_cat("U8", out, player_);
		print_cat("U6", out, player_);
	}
	else {//in search view
		while (itr != search_roster.end()) {
			player_ = itr->second;
			out << "Player " << count << "/" << s_roster_size << endl;
			out << "--------------------------------------\n";
			out << player_.get_lname() << ',' << player_.get_fname() << endl;
			out << player_.get_yob() << endl << player_.get_cat() << endl << player_.get_regstat() << endl;
			out << "--------------------------------------\n\n";
			count++;
			++itr;
		}
	}
}

int Roster::count_paid() {
	Player player_;
	num_paid = 0;
	auto itr = roster.begin();
	while (itr != roster.end()) {
		player_ = itr->second;
		if (player_.get_regstat() == true) ++num_paid;
		itr++;
	}
	return num_paid;
}

void Roster::read_file(const string& filename)
{
	ifstream in(filename);

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
	string fname, lname, category, str_reg_stat, str_yob, keyword;
	cout << "Please enter known information about player." << endl
		<< "If unknown leave field blank." << endl;
	cout << "First Name: ";
	getline(cin, fname);
	cout << "Last Name: ";
	getline(cin, lname);
	cout << "Category: ";
	getline(cin, category);
	cout << "Registration Status: ";
	getline(cin, str_reg_stat);
	cout << "Year of Birth: ";
	getline(cin, str_yob);
	cout << "Keyword: ";
	getline(cin, keyword);

	if (fname.empty() && category.empty() && str_reg_stat.empty() && str_yob.empty() && keyword.empty())
		search_roster[lname] = roster.find(lname)->second;
	else
		for (auto itr = roster.begin(); itr != roster.end(); ++itr)
		{
		Player player = itr->second;
		if (((fname.empty() || player.get_fname() == fname) &&
			(lname.empty() || player.get_lname() == lname) &&
			(category.empty() || player.get_cat() == category) &&
			(str_reg_stat.empty() || player.get_regstat() == stoi(str_reg_stat)) &&
			(str_yob.empty() || player.get_yob() == stoi(str_yob))) ||
			(fname.find(keyword) != string::npos) ||
			(lname.find(keyword) != string::npos) ||
			(category.find(keyword) != string::npos) ||
			(str_reg_stat.find(keyword) != string::npos) ||
			(str_yob.find(keyword) != string::npos))
				search_roster[lname] = player;
		}
}