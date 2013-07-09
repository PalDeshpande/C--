#include <iostream>
using std::cout;
using std::endl;
#include "Account.h"
Account::Account(){
	currentBalance = 0.0;
}

Account::Account(const string &name,float bal):accountOwner(name), currentBalance(bal){};
float Account::Deposit(float amount){
	count++;
	currentBalance = currentBalance + amount;
	return amount;
}

float Account::Withdraw(int amount){
	currentBalance = currentBalance-amount;
	return amount;
}
 Account Account::operator +(const Account &t1) {
	Account tempAccount;
	tempAccount.currentBalance=currentBalance + t1.currentBalance;

	return tempAccount;
}

void Account::postIncrement() {
	//if the value of second is greater than 59 increase the value of minutes
	currentBalance = currentBalance +70;
}
void Account::preIncrement() {
	//if the value of second is greater than 59 increase the value of minutes
	currentBalance = currentBalance +100;
}
//defining overloaded prefix ++ operator
 Account &Account::operator ++() {
	postIncrement(); // increments the value of the object and returns the incremented value
	return *this;
}
//definition of overloading postfix ++ operator
 Account Account::operator++(int) {
	Account tempAcc = *this;
	preIncrement(); // increments the object
	return tempAcc; //sends the value of the object before increament
}
float Account::Calculate(){

	return currentBalance;

}
/*float Account ::Calculate(){
	float rate;
	int balFraction;
	currentBalance = currentBalance - (currentBalance*rate);
	return currentBalance;

}*/
string Account::getOwner(){
	return accountOwner;
}
void Account::getCount(){
	cout<<"There are in total " <<count<< "accounts of both saving and checking account"<<endl;
}
int Account::count = 0;
