#ifndef Account_h
#define Account_h
#include <string>
#include <fstream>
using namespace std;
//class definition
class Account {
	 string accountOwner;
protected:
	float currentBalance;
	static int count;
public:
	//constructor
	Account();
	Account(const string &, float = 0.0);
	~Account() {
	}
	float Deposit(float amount);
	float Withdraw(int $);
	float Calculate();
	string getOwner();
	Account operator +(const Account &t1);
	void postIncrement();
	void preIncrement();
	Account &operator++();
	Account operator++(int);
	void getCount();

};

#endif

