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

void Roster::print_roster(const bool search, const string& file_name) {
	ofstream out(file_name);
	Player player_;
	auto itr = roster.begin();
	int count = 0;
	int s_roster_size = search_roster.size();
	if (!search) {//in main view
		print_cat("U17", out, player_);
		print_cat("U14", out, player_);
		print_cat("U12", out, player_);
		print_cat("U10", out, player_);
		print_cat("U8", out, player_);
		print_cat("U6", out, player_);
	}
	else {//in search view
		while (itr != search_roster.end()) {
			Player player = itr->second;
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
	search_roster.clear();
	int_current_player_ = 1;
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
	bool reg_stat = false;
	if (str_reg_stat == "Paid" || str_reg_stat == "paid" || str_reg_stat == "1")
		reg_stat = true;

	if (fname.empty() && category.empty() && str_reg_stat.empty() && str_yob.empty() && keyword.empty())
		search_roster[lname] = roster.find(lname)->second;
	else
		for (roster_map_::iterator itr = roster.begin(); itr != roster.end(); ++itr)
		{
		Player player = itr->second;
		if ((fname.empty() || player.get_fname() == fname) &&
			(lname.empty() || player.get_lname() == lname) &&
			(category.empty() || player.get_cat() == category) &&
			(str_reg_stat.empty() || player.get_regstat() == reg_stat) &&
			(str_yob.empty() || player.get_yob() == stoi(str_yob)) &&
			(keyword.empty()))
				search_roster[player.get_lname()] = player;
		if ((!keyword.empty()) &&
			((player.get_fname().find(keyword) != string::npos) ||
			(player.get_lname().find(keyword) != string::npos)))
				search_roster[player.get_lname()] = player;
		}
	itr_current_player_ = search_roster.begin();
}

void Roster::display_current_player()
{
	if (search_roster.empty())
	{ 
		cout << "Could not find any results which match search." << endl;
		return;
	}
	Player player = itr_current_player_->second;

	std::cout << "Player " << int_current_player_ << '/' << search_roster.size() << endl
		<< player.get_lname() << ", " << player.get_fname() << endl
		<< player.get_yob() << endl
		<< player.get_cat() << endl;
	if (player.get_regstat() == true)
		cout << "Paid" << endl;
	else if (player.get_regstat() == false)
		cout << "Unpaid" << endl;
}

void Roster::display_next_player()
{
	itr_current_player_++;
	int_current_player_++;
	if (itr_current_player_ == search_roster.end())
	{
		itr_current_player_ = search_roster.begin();
		int_current_player_ = 1;
	}
}

void Roster::display_prev_player()
{
	if (itr_current_player_ == search_roster.begin())
	{
		itr_current_player_ = --search_roster.end();
		int_current_player_ = search_roster.size();
	}
	else
	{
		itr_current_player_--;
		int_current_player_--;
	}
}

void Roster::update(){
	Player player_ = itr_current_player_->second;
	player_.edit();
}