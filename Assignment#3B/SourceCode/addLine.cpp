//============================================================================
// Name        : addLine.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Adding a new record to the test.txt file
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	string ID, firstName, LastName;
	fstream myfile;
	myfile.open("test.txt", ios_base::out | ios_base::app);
	cout << "enter student record, ID, firstName,and last Name";
	cout << endl;
	cin >> ID >> firstName >> LastName;

	myfile << endl << ID << " " << firstName << " " << LastName << endl;

	return 0;
}
