//============================================================================
// Name        : CommandLineEditor.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

//function declarations

void createFile();
void openFile(string fName);
void addLine(string line);
string encryptLine(string &str);
string decryptLine(string &line);
void openExistingFile();
void createTableFile();
void createListFile();
bool checkRecords(string fileName);
void createNewTableFile(string fileName);
void createNewListFile(string fileName);
void showErrorMsg(string msg);
void makeARecord(string fileName);
void showFiles();
void deleteFile(string name);
#define RECORDS_FILE "Records.txt"

int main() {
	char choice, validBit, choiceOp;
	string fileName;
	ifstream fileRecord;
	cout << "Do you perform file operations?" << endl;
	cin >> choiceOp;
	if (choiceOp == 'y') {
		validBit = 1;
	}

	do {
		cout << "Select file operation from following: " << endl;
		cout << "1. Create File" << endl;
		cout << "2. Edit File" << endl;
		cout << "3. Open existing file" << endl;
		cout << "4. Delete a File" << endl;
		//cout << "5. Show list of files" << endl;
		cin >> choice;
		if (choice == '1') {
			//call to create a file
			createFile();
		} else if (choice == '3') {
			//call to open a file
			openExistingFile();
		} else if (choice == '2') {
			string fileLine, fileName;
			showFiles();
			cout << "Enter the name of the file that you want edit" << endl;
			cin >> fileName;
			if (checkRecords(fileName)) {
				//if file name is valid allow user to add data to file
				addLine(fileName);
			} else {
				cout << "File name is incorrect" << endl;
			}
		} else if (choice == '4') {
			string fileName;
			showFiles();
			cout << "enter the name of file to delete" << endl;
			cin >> fileName;
			if (checkRecords(fileName)) {
				deleteFile(fileName);
			}
		}

		else
			cout << "Invalid choice of operation" << endl;
		cout << "Do you want to continue?" << endl;
		cin >> choice;
		if (choice == 'y') {
			validBit = 1;
		} else {
			validBit = 0;
			cout << "Thank you for using command line editor" << endl;
		}
	} while (validBit);

	return 0;
}

//function definitions

void createFile() {
	char format;
	cout << "Please choose file format: " << endl;
	cout << "1. Table" << endl;
	cout << "2. List" << endl;
	cin >> format;

	if (format == '1') {
		createTableFile();
	} else if (format == '2') {
		createListFile();
	} else
		cout << "Invalid file format request" << endl;

}

//function to create a file in list format

void createListFile() {
	string fileName;
	cout << "Welcome, Lets create a file with table format" << endl;
	cout << "Please enter a file name starting with L " << endl;
	cin >> fileName;
	if (!fileName.empty()) {
		int t_pos = fileName.find('L');
		if (t_pos == 0 && !checkRecords(fileName)) {
			makeARecord(fileName);
			createNewListFile(fileName);
		} else {
			showErrorMsg("File name should start with L");
		}
	} else {
		showErrorMsg("Invalid file name");
	}

}

//function to check ifname is valid to create a file in table format

void createTableFile() {
	string fileName;
	cout << "Welcome, Lets create a file with table format" << endl;
	cout << "Please enter a file name starting with T " << endl;
	cin >> fileName;
	if (!fileName.empty()) {
		int t_pos = fileName.find('T');
		if (t_pos == 0 && !checkRecords(fileName)) {
			makeARecord(fileName);
			createNewTableFile(fileName);
		} else {
			showErrorMsg("File name should start with T");
		}
	} else {
		showErrorMsg("Invalid file name");
	}
}

//make entry of file name in Records.txt when a new file is created

void makeARecord(string fileName) {
	string line;
	fstream newFile;
	if (!fileName.empty()) {
		newFile.open("Records.txt", ios_base::out | ios_base::app);
		newFile << fileName << endl;
	}

}

void createNewTableFile(string fileName) {
	fstream newFile;
	if (!fileName.empty()) {
		newFile.open(fileName.c_str(), ios_base::out | ios_base::app);
		int columns = 0, rows = 0;
		cout << "How many columns do you want?" << endl;
		cin >> columns;
		cout << "How many rows you want?" << endl;
		cin >> rows;
		if (columns > 0 && rows > 0) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns;) {
					string line;
					cout << "enter the  entry[" << i << "]" << "[" << j << "]"
							<< endl;

					while (std::getline(std::cin, line) && !line.empty()
							&& strcmp(line.c_str(), "\n") != 0) {

						cout << "Input " << line << endl;
						string encryptedLine = encryptLine(line);
						newFile << encryptedLine << setw(10);
						j++;
						break;

					}

				}
				newFile << endl;
			}
		} else {
			showErrorMsg("Please provide valid rows & columns");
		}
		newFile.close();
	} else {
		showErrorMsg("Please provide valid filename");
	}
}

void createNewListFile(string fileName) {
	fstream newFile;
	if (!fileName.empty()) {
		newFile.open(fileName.c_str(), ios_base::out | ios_base::app);
		int items = 0;
		cout << "How many items do you want in list?" << endl;
		cin >> items;
		string line;
		if (items > 0) {
			for (int i = 0; i < items;) {
				cout << "Please enter item " << i << endl;
				while (std::getline(std::cin, line) && !line.empty()
						&& strcmp(line.c_str(), "\n") != 0) {

					cout << "Input " << line << endl;
					string encryptedLine = encryptLine(line);
					newFile << encryptedLine << setw(10);
					newFile << endl;
					i++;
					break;
				}

			}
		} else {
			showErrorMsg("Please provide valid rows & columns");
		}
		newFile.close();
	} else {
		showErrorMsg("Please provide valid filename");
	}
}

//check if file name exists in records
bool checkRecords(string fileName) {
	bool isExist = false;
	if (!fileName.empty()) {
		string fileLine;
		ifstream fileRecord;
		fileRecord.open(RECORDS_FILE, ifstream::in);
		if (fileRecord.is_open()) {
			cout << "Checking for filename..." << endl;
			while (fileRecord.good()) {
				getline(fileRecord, fileLine);
				cout << fileLine << endl;
				if (strcmp(fileLine.c_str(), fileName.c_str()) == 0) {
					cout << "File with this name already exists !!" << endl;
					isExist = true;
					break;
				}
			}
			fileRecord.close();
		} else {
			showErrorMsg("Sorry unable to open file, file does not exist!!");
		}
	} else {
		showErrorMsg("Please provide valid filename");
	}
	return isExist;

}

void openExistingFile() {
	string fileName;
	cout << "Available files are: " << endl;
	showFiles();
	cout << "Please enter a file " << endl;
	cin >> fileName;
	if (!fileName.empty()) {
		string fileLine;
		ifstream fileRecord;
		fileRecord.open(fileName.c_str(), ifstream::in);
		if (fileRecord.is_open()) {
			cout << "Opening file..." << endl;
			cout << "File Content as bellow." << endl;
			cout << "*****************************" << endl;
			while (fileRecord.good()) {

				getline(fileRecord, fileLine);
				string dcryptedLine = decryptLine(fileLine);
				cout << dcryptedLine << endl;

			}
			cout << "*****************************" << endl;
			cout << "Closing file..." << endl;
			fileRecord.close();

		} else {
			showErrorMsg("Sorry unable to open file, file does not exist!!");
		}
	} else {
		showErrorMsg("Please provide valid filename");
	}
}

//function to display error messages

void showErrorMsg(string msg) {
	cout << "ERROR :" + msg << endl;
}

void openFile(string fName) {
	string line, decryptedLine;
	ifstream myfile;
	myfile.open(fName.c_str());
	while (!myfile.eof()) {
		getline(myfile, line);
		decryptedLine = decryptLine(line);
		cout << decryptedLine << endl;
	}
}

//function to encrypt a file
string encryptLine(string &line) {
	int length = line.length();
	char strChar;
	string rstr;
	for (int k = 0; k < length / 2; k++) {
		strChar = line[k];
		line[k] = line[length - k - 1];
		line[length - k - 1] = strChar;

	}
	return line;

}

//function to decrypt file content

string decryptLine(string &line) {
	int length = line.length();
	char strChar;
	string rstr;
	for (int k = 0; k < length / 2; k++) {
		strChar = line[k];
		line[k] = line[length - k - 1];
		line[length - k - 1] = strChar;

	}
	return line;

}

//function to allow user to add data

void addLine(string fileName) {
	int columns, rows;
	string line;
	fstream myfile;

	int pos = fileName.find('T');
	if (pos == 0) {

		myfile.open(fileName.c_str(), ios_base::out | ios_base::app);
		cout << "How many columns do you want?" << endl;
		cin >> columns;
		cout << "How many rows you want?" << endl;
		cin >> rows;
		if (columns > 0 && rows > 0) {
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < columns;) {
					string line;
					cout << "enter the  entry[" << i << "]" << "[" << j << "]"
							<< endl;

					while (std::getline(std::cin, line) && !line.empty()
							&& strcmp(line.c_str(), "\n") != 0) {

						cout << "Input " << line << endl;
						string encryptedLine = encryptLine(line);
						myfile << encryptedLine << setw(10);
						j++;
						break;

					}

				}
				myfile << endl;
			}
		} else
			cout << "Invalid rows and colums entered" << endl;
	} else {
		if (!fileName.empty()) {

			int pos1 = fileName.find('L');
			if (pos1 == 0) {
				myfile.open(fileName.c_str(), ios_base::out | ios_base::app);
				int items = 0;
				cout << "How many items do you want in list?" << endl;
				cin >> items;
				string line;
				if (items > 0) {
					for (int i = 0; i < items;) {
						cout << "Please enter item " << i << endl;
						while (std::getline(std::cin, line) && !line.empty()
								&& strcmp(line.c_str(), "\n") != 0) {

							cout << "Input " << line << endl;
							string encryptedLine = encryptLine(line);
							myfile << encryptedLine << setw(10);
							myfile << endl;
							i++;
							break;
						}

					}

				}
			}
		}
		cout << "File name is invalid" << endl;

	}
}

void showFiles() {
	string fileLine;
	ifstream fileRecord;
	//show the list of files created using this program
	fileRecord.open("Records.txt", ifstream::in);
	if (fileRecord.is_open()) {
		cout << "Opening record..." << endl;
		cout << "List of existing file: " << endl;
		cout << "*****************************" << endl;
		while (fileRecord.good()) {

			getline(fileRecord, fileLine);
			cout << fileLine << endl;

		}
		cout << "*****************************" << endl;
		cout << "Closing records..." << endl;
		fileRecord.close();

	}
}

//additional feature that allows user to delete a file
void deleteFile(string name) {
	string fileLine;
	ifstream fileRecord;
	ofstream output_file("result.txt");
	if (remove(name.c_str()) != 0)
		perror("Error deleting file");
	else
		puts("File successfully deleted");
	//edit the records
	fileRecord.open("Records.txt", ifstream::in);
	if (fileRecord.is_open()) {

		while (fileRecord.good()) {

			getline(fileRecord, fileLine);
			int pos = fileLine.find(name.c_str());
			if (pos < 0) {
				output_file << fileLine << endl;

			}

		}
		output_file.close();
		remove("Records.txt");
		rename("result.txt", "Records.txt");

		fileRecord.close();

	}

}
