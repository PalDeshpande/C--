//============================================================================
// Name        : midterm.cpp
// Author      : Pallavi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
using namespace std;
class Account {
protected:
	string accName, type;
	double balance;
	int rate;
public:
	void credit(double a);
	void debit(double deb);
	double getBal() ;
	void setBal(double bal);
	void GetType();
	string getName(){
		return this->accName;
	}

};
class Saving: public Account {
	int interest, balance;
public:
	Saving(){}
	Saving(string name, double bal){accName=name;
	balance = bal;
	}
	~Saving(){}

	void setInterest(int rate) {
		interest = rate;

	}
	int getInterest() {
		return interest;
	}
	double getBal() {
			return this->balance;

		}
	void setBal(double bal) {
		this->balance = bal;
	}
	void credit(double a) {
		balance = balance + a;
		//return balance;

	}
	void getType(){
		cout<< "it is an saving account \n";

	}

};
class Checking: public Account {
	int interest;
	double balance;
public:
	Checking();
	Checking(string name, double bal){
		accName = name;
		balance = bal;
	}
	~Checking() {
	}

	void setInterest(int rate) {
		interest = rate;

	}
	int getInterest() {
		return interest;
	}
	double getBal() {
			return this->balance;

		}
	void setBal(double bal) {
			this->balance = bal;
		}
	double Withdraw(int fees) {
		int balance = this->balance;
		return (balance - fees);
	}
	void debit(double deb) {
		double bal;
		bal = Withdraw(10);
		if (bal - deb > 0) {
			bal = bal - deb;
			this->balance = bal;
		} else
			cout << "insufficient balace" << endl;
	}
	void GetType(){
			cout<< "it is an checking account \n";

		}
};

int main() {
	Saving s("kd", 200);
	Checking c("pd", 200);
	s.setInterest(3);
	c.setInterest(1);
	c.debit(50);
	s.credit(100);
	string name =  s.getName();
	cout<<" Account holder is : "<<name<<endl;
	s.getType();
	double balance0 = s.getBal();
	cout<<"balance is"<<balance0<<endl;

	string Name = c.getName();
cout<< "Acc holder is :"<<Name<<endl;

	c.GetType();
	double balance =c.getBal();
	cout<<"Balance is"<<balance<<endl;
	return 0;
}
