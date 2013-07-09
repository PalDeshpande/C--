//============================================================================
// Name        : deleteLine.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Program to delete line from a file in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	string Line, Findstring;

	cout << "Enter name who's record you want to delete" << endl;
	cin >> Findstring;

	fstream input_file("original.txt", ios::in);
	ofstream output_file("result.txt");

	while (!input_file.eof()) {
		getline(input_file, Line);

		int spot = Line.find(Findstring);
		if (spot < 0) {
			output_file << Line << endl;
		}

	}
	remove("original.txt");
	rename("result.txt", "original.txt");
}
