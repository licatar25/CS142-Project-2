#ifndef _Player_
#define _Player_
#include <iostream>

class Player//contains the actual information of each player
{
public:
	Player() : f_name_("Undefined"),l_name_("Undefined"), yob_(9999),reg_stat_(false) {}
	Player(std::string fname, std::string lname, int yob, bool reg_stat,int season_year) : 
		f_name_(fname), l_name_(lname), yob_(yob), reg_stat_(reg_stat) {
		age_ = season_year - yob_;
		calc_category();
	}
	inline std::string get_lname() { return l_name_; }
	inline std::string get_fname() { return f_name_; }
	inline int get_yob() { return yob_; }
	inline bool get_regstat() { return reg_stat_; }
	inline std::string get_cat() { return category_; }
	inline int get_age() { return age_; }
private:
	void calc_category();
	std::string f_name_;
	std::string l_name_;
	int yob_;
	bool reg_stat_;
	int age_;
	std::string category_;
	std::string error_message = "Player too young or too old. ";//maybe expand on this
};

void Player::calc_category() {
	if ((age_ < 17) && (age_ >= 14)) category_ = "U17";
	if ((age_ < 14) && (age_ >= 12)) category_ = "U14";
	if ((age_ < 12) && (age_ >= 10)) category_ = "U12";
	if ((age_ < 10) && (age_ >= 8)) category_ = "U10";
	if ((age_ < 8) && (age_ >= 6)) category_ = "U8";
	if ((age_ < 6) && (age_ >= 4)) category_ = "U6";
};
#endif