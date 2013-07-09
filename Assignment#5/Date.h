# ifndef DATE_H
# define DATE_H
//class definition
class Date{
	int day, month , year;
	static int count;
public:
	Date ();
	~Date(){}
	int getDate(){return day, month, year;}
	void setDate(int D, int M, int Y);
	void printDate();
};
//count variable to keep the count of no of objects of the class Date being created
int Date::count = 0;
#endif
