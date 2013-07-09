#include <iostream>
using std::cout;
using std::endl;
#include "Savings.h"
Savings::Savings(){
	currentBalance = 0.0;
}

Savings::Savings(const string &name, float bal) :
		Account(name, bal) {
	count++;
	acctype = "Savings";
}
float Savings::Calculate() {
	float rate;
	int balFraction;
	if (currentBalance < 2500) {
		rate = 0.03;
	} else {
		balFraction = currentBalance / 2500;
		rate = 0.03+( 0.0025 * balFraction);
	}

	currentBalance = currentBalance + (currentBalance * rate);
	return currentBalance;

}
Savings Savings::operator +(const Savings &t1) {
	Savings tempSavings;
	tempSavings.currentBalance=currentBalance + t1.currentBalance;

	return tempSavings;
}

void Savings::postIncrement() {
	//if the value of second is greater than 59 increase the value of minutes
	currentBalance = currentBalance +70;
}
void Savings::preIncrement() {
	//if the value of second is greater than 59 increase the value of minutes
	currentBalance = currentBalance +100;
}
//defining overloaded prefix ++ operator
 Savings &Savings::operator ++() {
	postIncrement(); // increments the value of the object and returns the incremented value
	return *this;
}
//definition of overloading postfix ++ operator
 Savings Savings::operator++(int) {
	Savings tempAcc = *this;
	preIncrement(); // increments the object
	return tempAcc; //sends the value of the object before increament
}
/*float Savings::Calculate(){
 float rate;
 int balFraction;
 if(currentBalance <2500){
 rate = 0.03;
 }
 else{
 balFraction = currentBalance/2500;
 rate = 0.03*balFraction;
 }

 currentBalance = currentBalance - (currentBalance*rate);
 return currentBalance;

 }*/
//operator << overloaded
ostream &operator<<(ostream &out, Savings &depositamt) {
	float Bal;
	string Owner;
	Bal = depositamt.Calculate();
	Owner = depositamt.getOwner();
	out << "This is " << depositamt.acctype << " account of" << Owner
			<< " and the current balance is " << Bal << endl;
	return out;
}

