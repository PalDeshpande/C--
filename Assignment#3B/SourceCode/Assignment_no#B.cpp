//============================================================================
// Name        : Ass3B.cpp
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

int main(int argc, char *argv[]) {

	string line, LastName;
	int size;
	ofstream outputfile("output.txt");

	// argument count argc should be 2 as per program requirement
	if (argc != 2) {
		//  argv[0] printed assuming it is the program name
		cout << "usage: " << argv[0] << " <data.txt>\n";
	} else {
		// We assume argv[1] is a filename to open
		ifstream myfile(argv[1]);
		//  Checking for file opening operation
		if (!myfile.is_open()) {
			cout << "Could not open file\n";
		} else {

			while (!myfile.eof()) {
				//retrieve a string from text file
				getline(myfile, line);
				if (line.empty())
					continue;
				//find the ',' in the text file with assumption that,
				//there is comma after first name then space and then last name
				int pos = line.find(",");
				LastName = line.substr(pos + 1);
				size = sizeof(LastName);
				//Convert the last Name to capital
				transform(LastName.begin(), LastName.end(), LastName.begin(),
						::toupper);
				if (outputfile.is_open()) {
					const char * pLastName = LastName.c_str();
					cout << pLastName << endl;
					//the last name in capital letter is written to the output file
					outputfile<<pLastName<<endl;
				}

			}
		}
	}
	return 0;
}
