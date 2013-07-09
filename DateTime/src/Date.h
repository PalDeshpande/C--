# ifndef DATE_H
# define DATE_H
//class definition
#include <string>
using namespace std;
class Date{
	int day, month , year;

public:
	Date ();
	Date(int D, int mon, int yr);
	~Date(){}
	string getDate();
	void setDate(int D, int M, int Y);
};
#endif
