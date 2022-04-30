#include "Player.h"
using namespace std;

void Player::calc_category() {
	if ((age_ < 17) && (age_ >= 14)) category_ = "U17";
	if ((age_ < 14) && (age_ >= 12)) category_ = "U14";
	if ((age_ < 12) && (age_ >= 10)) category_ = "U12";
	if ((age_ < 10) && (age_ >= 8)) category_ = "U10";
	if ((age_ < 8) && (age_ >= 6)) category_ = "U8";
	if ((age_ < 6) && (age_ >= 4)) category_ = "U6";
};

void Player::edit(){
	cout << "Enter the information you want to modify." << endl
		<< "Leave blank if you do not want to make a change";
	string fname, lname, yob, reg_stat;
	cout << "First Name: ";
	getline(cin, fname);
	cout << "Last Name: ";
	getline(cin, lname);
	cout << "Year of Birth: ";
	getline(cin, yob);
	cout << "Registration Status: ";

	if (!fname.empty())
		f_name_ = fname;
	if (!lname.empty())
		l_name_ = lname;
	if (!yob.empty())
	{
		yob_ = stoi(yob);
		calc_category();
	}
	if (!reg_stat.empty())
	{
		reg_stat_ = false;
		if (reg_stat == "paid" || reg_stat == "Paid" || reg_stat == "1")
			reg_stat_ = true;
	}

	/*char command;
	string replace;
	int replace_int;*/
	//cout << "Please choose the information that you want to edit for this player, or press enter if you don't wish to make changes:" << endl
	//	<< "1. Last Name\n2. First Name\n3. Year of Birth\n4. Registration Status\n";
	//cin >> ws;
	//if (cin.get(command)) {
	//	cout << "Please enter what you wish to relace this information with: ";
	//	cin >> replace;
	//	switch (command)
	//	{
	//	case '1': f_name_ = replace;
	//	case '2': l_name_ = replace;
	//	case '3': {replace_int = stoi(replace);
	//		yob_ = replace_int;
	//	}
	//	case '4': {while ((replace != "Paid") || (replace != "paid") || (replace != "unpaid") || (replace != "Unpaid")) {
	//		cout << "Enter a valid registration status: ";
	//		cin >> replace;
	//	}
	//	}
	//			if ((replace == "Paid") || (replace == "paid")) reg_stat_ = true;
	//			if ((replace == "unpaid") || (replace == "Unpaid")) reg_stat_ = false;
	//	}
	//}
}