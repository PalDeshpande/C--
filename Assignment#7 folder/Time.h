#ifndef Time_h
#define Time_h
#include <string>
#include <fstream>
using namespace std;
//class definition
class Time {
	friend ostream &operator<<(ostream &output, const Time &t);
private:
	int hour, minutes, second;
	string hr;
public:
	//check if time entered is valid
	Time();
	Time(int hr, int min, int sec);
	~ Time(){}
	string getTime();
	 Time operator +(const Time &t1);
	 Time operator =( const Time &t2);
	 void increment();
	 Time &operator++();
	 Time operator++(int);
	 void decrement();
	 Time &operator--();
	 Time operator--(int);
};
#endif
