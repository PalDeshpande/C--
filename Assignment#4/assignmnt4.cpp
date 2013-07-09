//============================================================================
// Name        : Time.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Class usage and object creation
//============================================================================

#include <iostream>
#include "Time.h"
using namespace std;

//Defination of class methods
int Time::getTime(){
	return hour, minutes, second;
}



//method to set and then  validate entered time
void Time::setValidateTime(int Hr, int minits, int Secs) {
	//hour should be in the range of 0 to 23
	hour = ((Hr >= 0 && Hr <= 23) ? Hr : 0);
	//hour conversion to 12 hr format
	if(hour>12){
		hour = hour-12;
	}
	//minutes should be in the range of 0 t0 59
	minutes = ((minits >= 0 && minits <= 59) ? minits : 0);
	//seconds should be in the range of 0 t0 59
	second = ((Secs >= 0 && Secs <= 59) ? Secs : 0);
}

// method to display time

void Time::printTime() {
	cout << "Time is ";
	cout << hour << ":" << minutes << ":" << second;

	if (hour > 11) {

		cout << "pm" << endl;
	}

	else
		cout << "am" << endl;
}

int main() {

	Time Time;
	int hr, min, sec;
	//input from user
	cout << "enter time" << endl;
	cin >> hr >> min >> sec;
	Time.setValidateTime(hr, min, sec);
	Time.printTime();

	return 0;
}
