//============================================================================
// Name        : AssignmentNo7.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <string>
#include <fstream>
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
Time::Time(int hr, int min, int sec) {
	//hour should be in the range of 0 to 23
	hour = ((hr >= 0 && hr <= 23) ? hr : 0);
	//hour conversion to 12 hr format
	if (hour > 12) {
		hour = hour - 12;
	}
	//minutes should be in the range of 0 t0 59
	minutes = ((min >= 0 && min <= 59) ? min : 0);
	//seconds should be in the range of 0 t0 59
	second = ((sec >= 0 && sec <= 59) ? sec : 0);
}

string Time::getTime() {
	stringstream hr, min, sec;
	hr << hour;
	min << minutes;
	sec << second;

	return (hr.str() + ":" + min.str() + ":" + sec.str());

}
Time Time::operator +(const Time &t1) {
	Time tempTime;
	tempTime.hour = hour + t1.hour;
	tempTime.minutes = minutes + t1.minutes;
	tempTime.second = second + t1.second;
	return tempTime;
}
Time Time::operator =(const Time &t2) {
	Time tempTime;
	tempTime.hour = t2.hour;
	tempTime.minutes = t2.minutes;
	tempTime.second = t2.second;
	return tempTime;

}
ostream &operator<<(ostream &out, const Time &t) {

	out << t.hour << ":" << t.minutes << ":" << t.second;
	return out;

}
// increment the hour if value of minutes and second is more than 59
void Time::increment() {
	//if the value of second is greater than 59 increase the value of minutes
	if (second > 59) {
		minutes++;
		second = 0;
	}
	//if the value of minutes is greater than 59 increase the value of hour
	if (minutes > 59) {
		hour++;
		minutes = 0;
	}

}
//defining overloaded prefix ++ operator
Time &Time::operator ++() {
	increment(); // increments the value of the object and returns the incremented value
	return *this;
}
//definition of overloading postfix ++ operator
Time Time::operator++(int) {
	Time tempTime = *this;
	increment(); // increments the object
	return tempTime; //sends the value of the object before increament
}
//decrement values of minute and second if equal to 60
void Time::decrement() {
	//if value of second equal to 60 decrement
	if (second > 59) {
		second--;
	}
	//if the value of minutes is equal to 60 decrease it
	if (minutes > 59) {
		minutes--;

	}
}
//definition of overloading prefix -- operator
Time &Time::operator --() {
	decrement();
	return *this;
}
//definition of overloading postfix -- operator
Time Time::operator --(int) {
	Time timeTemp = *this;
	decrement();
	return timeTemp;
}

int main() {
	string strTime;
	Time t(5, 40, 20);
	Time t2(3, 40, 10);
	Time t3 = t + t2;
	Time t4(4, 61, 61);
	Time t5(7, 60, 60);
	strTime = t3.getTime();
	//testing prefix decrement operation
	cout << "--t4 " << "is " << --t4 << endl;
	//testing postfix decrement operation
	cout << "t5-- " << "is" << t4-- << endl;
	cout << t5 << endl;
	//testing << operator overloading
	cout << t3 << endl;
	//testing prefix increment operation
	cout << "++t3 " << "is " << ++t3 << endl;
	//testing postfix increment operation
	cout << "t3++" << "is " << t3++ << endl;
	cout << t3 << endl;

}

