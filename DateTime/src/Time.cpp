//============================================================================
// Name        : Time.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Class usage and object creation
//============================================================================

#include <iostream>
#include <string>
#include <ctime>
#include<sstream>
#include "Time.h";
using namespace std;
//class implementation
Time::Time() {
	time_t current = time(0);
	tm *localTime = localtime(&current);
	hour = localTime->tm_hour;
	minutes = localTime->tm_min;
	second = localTime->tm_sec;
}
Time::Time(int hr, int min, int sec){
	hour = hr;
	minutes = min;
	second = sec;
}

string Time::getTime() {
	stringstream hr, min, sec;
	hr << hour;
	min << minutes;
	sec << second;

	return (hr.str() + ":" + min.str() + ":" + sec.str());

}

//method to set and then  validate entered time
void Time::setValidateTime(int Hr, int minits, int Secs) {
	//hour should be in the range of 0 to 23
	hour = ((Hr >= 0 && Hr <= 23) ? Hr : 0);
	//hour conversion to 12 hr format
	if (hour > 12) {
		hour = hour - 12;
	}
	//minutes should be in the range of 0 t0 59
	minutes = ((minits >= 0 && minits <= 59) ? minits : 0);
	//seconds should be in the range of 0 t0 59
	second = ((Secs >= 0 && Secs <= 59) ? Secs : 0);
}





