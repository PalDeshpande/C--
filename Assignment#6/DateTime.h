# ifndef DATETime_H
# define DATETIME_H
//class definition
#include "Time.h"
#include "Date.h"
#include <string>
using namespace std;
class DateTime {
	Time time ;
	Date date;
public:
	string getTime();
	string getDate();
	void setDateTime(int day, int mon, int yr,int hr, int min, int sec);
	void setDate();
	string toString();
};
# endif
