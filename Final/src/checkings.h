#ifndef checkings_h
#define checkings_h
#include <string>
#include <fstream>
#include "Account.h"
using namespace std;

class checkings: public Account {
	checkings();
	friend ostream &operator<<(ostream &output, checkings &C);
private:
	 string accType;
public:
	checkings(const string &,double bal);
	float Calculate();
	~checkings(){}
	checkings operator +(const checkings &t1);
		void postIncrement();
		void preIncrement();
		checkings &operator++();
		checkings operator++(int);
		void getCount();

};

#endif
