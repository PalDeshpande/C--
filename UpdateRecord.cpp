//============================================================================
// Name        : UpdateRecord.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Program that updates records in a file in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	string singleLine, Tempstring, Updatingstring, Findstring;
	int pos;

	cout << "enter name" << endl;
	cin >> Findstring;
	cout << "enter replace";
	cin >> Updatingstring;

	fstream input("original.txt", ios::in);
	ofstream output_file("result.txt");

	while (!input.eof()) {
		getline(input, singleLine);

		pos = singleLine.find(Findstring);
		//if the desired string is found replace with new string and update the file
		if (pos >= 0) {
			Tempstring = singleLine.substr(0, pos);
			Tempstring += Updatingstring;
			Tempstring += singleLine.substr(pos + Findstring.length(), singleLine.length());
			singleLine = Tempstring;
		}

		output_file << singleLine << endl;
	}
	//After updating the record and saving the updates to result.txt
	//rename it to original file to get the modified file.
	remove("original.txt");
	rename("result.txt", "original.txt");
}
