//============================================================================
// Name        : Assignment5.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include "Date.h"
using namespace std;

//setter function to set date as per user specification
void Date::setDate(int D, int M, int Y) {
	day = D;
	month = M;
	year = Y;
}
//constructor to assign current date
Date::Date() {
	count++;
	time_t current = time(0);
	tm *localTime = localtime(&current);
	day = localTime->tm_mday;
	month = 1 + localTime->tm_mon;
	year = 1900 + localTime->tm_year;

}
// function to print the date
void Date::printDate() {
	cout << "Today's Date: " << endl;
	cout << month << "/" << day << "/" << year << endl;
}

int main() {
	//compile time object
	Date Date1;
	// runtime object i.e dynamic object
	Date *Date2 = new Date;
	Date1.printDate();
	//deleting the runtime object
	Date2->printDate();
	delete Date2;
	return 0;
}
