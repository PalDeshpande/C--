#include <iostream>
using std::cout;
using std::endl;
#include "checkings.h"
checkings::checkings(){
	currentBalance = 0.0;
}

checkings::checkings(const string &name, double bal) :
		Account(name, bal) {
	count++;

	accType = "Checkings";
}
float checkings::Calculate() {
	float rate;
	int balFraction;
	if (currentBalance < 100) {
		rate = 0.05;
	} else {
		balFraction = currentBalance / 2500;
		rate = 0.05 - (0.0025 * balFraction);
	}
	currentBalance = currentBalance - (currentBalance * rate);
	return currentBalance;

}
ostream &operator<<(ostream &out, checkings &checkamount) {
	float Bal;
	string Owner;
	Bal = checkamount.Calculate();
	Owner = checkamount.getOwner();
	out << "This is " << checkamount.accType << " account of" << Owner
			<< "Current balance is :" << Bal << endl;
	return out;

}
checkings checkings::operator +(const checkings &t1) {
	checkings tempcheckings;
	tempcheckings.currentBalance=currentBalance + t1.currentBalance;

	return tempcheckings;
}

void checkings::postIncrement() {
	//if the value of second is greater than 59 increase the value of minutes
	currentBalance = currentBalance +70;
}
void checkings::preIncrement() {
	//if the value of second is greater than 59 increase the value of minutes
	currentBalance = currentBalance +100;
}
//defining overloaded prefix ++ operator
 checkings &checkings::operator ++() {
	postIncrement(); // increments the value of the object and returns the incremented value
	return *this;
}
//definition of overloading postfix ++ operator
 checkings checkings::operator++(int) {
	 checkings tempAcc = *this;
	preIncrement(); // increments the object
	return tempAcc; //sends the value of the object before increament
}

