//============================================================================
// Name        : UpdateRecord.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	string Line, Tempstring, Updatingstring, Findstring;
    int pos;

	cout << "enter name" << endl;
	cin >> Findstring;
	cout << "enter replace";
	cin >> Updatingstring;

	fstream input("demo.txt", ios::in);
	ofstream output_file("result.txt");

	while (!input.eof()) {
		getline(input, Line);

		 pos = Line.find(Findstring);
		//if the desired string is found replace with new string and update the file
		if (pos >= 0) {
			Tempstring = Line.substr(0, pos);
			Tempstring += Updatingstring;
			Tempstring += Line.substr(pos + Findstring.length(),
					Line.length());
			Line = Tempstring;
		}

		output_file << Line << endl;
	}
	//After updating the record and saving the updates to result.txt
	//rename it to original file to get the modified file.
	remove("original.txt");
	rename("result.txt", "original.txt");
}
