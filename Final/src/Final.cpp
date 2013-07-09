//============================================================================
// Name        : Final.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include<iomanip>
#include "Account.h"
#include "Savings.h"
#include "checkings.h"
#include "CD.h"
#include <string>
using namespace std;

int main() {

	string first = "Pallavi"; // use your name !!
	string last = "Keskar";
	Savings s(first, 3000); // saving starts with 3000
	checkings c(last, 7000); // checking starts with 7000

	// create an output file to store result
	// more points if you add file exception handling
	ofstream outfile;
	outfile.open((last + "." + first + ".txt").c_str(),
			ios_base::out | ios_base::app);
	outfile << "BEG" << endl << s << endl << c << endl;
	outfile.close();
	float deposit = c.Deposit(3000);
	cout << s << endl;
	outfile.open((last + "." + first + ".txt").c_str(),
			ios_base::out | ios_base::app);
	outfile << "Account owner" << first << " deposited " << "$" << deposit
			<< " in" << "account" << endl;
	outfile.close();
	float withdraw = c.Withdraw(400);
	outfile.open((last + "." + first + ".txt").c_str(),
			ios_base::out | ios_base::app);
	outfile << "Account owner" << first << " withrawed " << "$" << withdraw
			<< " from" << "account" << endl;
	outfile.close();

	Savings *s2p = new Savings("Obama", 2000);
	(*s2p)++;
	*s2p = s + (*s2p);
	delete s2p;

	++(++s);

	Account *ap;
	ap = &s;
	ap->Calculate();
	deposit = ap->Deposit(100);
	outfile.open((last + "." + first + ".txt").c_str(),
			ios_base::out | ios_base::app);
	outfile << "Account owner" << first << " deposited " << "$" << deposit
			<< " in" << "account" << endl;
	outfile.close();
	withdraw = ap->Withdraw(50);
	outfile.open((last + "." + first + ".txt").c_str(),
			ios_base::out | ios_base::app);
	outfile << "Account owner" << first << " withdrawed " << "$" << withdraw
			<< " from" << "account" << endl;
	outfile.close();
	ap = &c;
	ap -> Calculate();


	return 0;
}
