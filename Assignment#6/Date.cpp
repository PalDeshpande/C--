#include <iostream>
#include <string>
#include <ctime>
#include<sstream>
#include "Date.h"
using namespace std;
//class implementation
void Date::setDate(int D, int M, int Y) {
	day = D;
	month = M;
	year = Y;
}
//constructor to assign current date
Date::Date() {

	time_t current = time(0);
	tm *localTime = localtime(&current);
	day = localTime->tm_mday;
	month = 1 + localTime->tm_mon;
	year = 1900 + localTime->tm_year;

}
Date::Date(int D, int mon, int yr){
	day = D;
	month = mon;
	year = yr;

}
// function to print the date
string Date::getDate() {
	stringstream strday, strmon, stryear;
	string strDate;
	strday << day;
	strmon << month;
	stryear << year;
	return strmon.str() + "/" + strday.str() + "/" + stryear.str();

}
