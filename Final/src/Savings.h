/*
 * Savings.h
 *
 *  Created on: Apr 10, 2012
 *      Author: Pallavi
 */
#ifndef SAVINGS_H_
#define SAVINGS_H_
#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include "Account.h"
using namespace std;
class Savings: public Account {
	Savings();
	friend ostream &operator<<(ostream &output, Savings &s);
private:
	string acctype;
public:
	Savings(const string &, float = 0.0);
	~Savings() {
	}
	Savings operator +(const Savings &t1);
	float Calculate();
	void postIncrement();
	void preIncrement();
	Savings &operator++();
	Savings operator++(int);
	void getCount();

};

#endif  /*SAVINGS_H_*/
