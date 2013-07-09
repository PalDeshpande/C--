#ifndef Time_h
#define Time_h
#include <string>
using namespace std;
//class definition
class Time {
private:
	int hour, minutes, second;
	string hr;
public:
	//check if time entered is valid
	Time();
	Time(int hr, int min, int sec);
	~ Time(){}
	string getTime();
	void setValidateTime(int Hr, int Min, int Sec);
};
#endif
