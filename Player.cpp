#include "Player.h"

void Player::calc_category() {
	if ((age_ < 17) && (age_ >= 14)) category_ = "U17";
	if ((age_ < 14) && (age_ >= 12)) category_ = "U14";
	if ((age_ < 12) && (age_ >= 10)) category_ = "U12";
	if ((age_ < 10) && (age_ >= 8)) category_ = "U10";
	if ((age_ < 8) && (age_ >= 6)) category_ = "U8";
	if ((age_ < 6) && (age_ >= 4)) category_ = "U6";
};
