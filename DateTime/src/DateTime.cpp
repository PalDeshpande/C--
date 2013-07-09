//============================================================================
// Name        : DateTime.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<ctime>
#include "DateTime.h"
using namespace std;

//class implementation
string DateTime::getTime() {
	string timestr;
	timestr = time.getTime();
	return timestr;
}
string DateTime::getDate() {
	string strDate;
	strDate = date.getDate();

	return strDate;
}
void DateTime::setDateTime(int day, int mon, int yr, int hr, int min, int sec) {
	date.setDate(day, mon, yr);
	time.setValidateTime(hr, min, sec);

}
string DateTime::toString() {
	string sdate, sTime, strDateTime;
	sdate = getDate();
	sTime = getTime();
	strDateTime = "date: " + sdate + " Time: " + sTime;
	return strDateTime;
}

int main() {
	string dateTime;
	//array of 9 dynamically created objects
	DateTime *datetime = new DateTime[9];
	DateTime datetime1;
	DateTime dt;
	//object of DateTime class with prespecified date and time
	datetime1.setDateTime(11, 01, 2012, 9, 12, 30);
	dateTime = datetime1.toString();
	cout<<dateTime<<endl;
	dateTime = datetime[0].toString();
	cout << dateTime << endl;
	return 0;
}
