#include <vector>
#include <iostream>
#include <memory>
using namespace std;

class Date
{
private:
	size_t _day;
	size_t _month;
	size_t _year;
	friend ostream& operator<<(ostream& os, const Date& date);
public:
	Date(size_t day, size_t month, size_t year): _day(day), _month(month), _year(year) {}
	Date() {}
	void setDay(size_t day)
	{
		_day = day;
	}
	void setMonth(size_t month)
	{
		_month = month;
	}
	void setYear(size_t year)
	{
		_year = year;
	}
	size_t getDay()
	{
		return _day;
	}
	size_t getMonth()
	{
		return _month;
	}
	size_t getYear()
	{
		return _year;
	}
};
ostream& operator<<(ostream& os, const Date& date)
{
    os << date._day << "." << date._month << "." << date._year;
	return os;
}
void compare(unique_ptr<Date>& date1, unique_ptr<Date>& date2)
{
	cout << ((date1->getDay() > date2->getDay()) ? *date1 : *date2) << endl;
}
void swap(unique_ptr<Date>& date1, unique_ptr<Date>& date2)
{
	unique_ptr<Date> buf = move(date1);
	date1 = move(date2);
	date2 = move(buf);
}
int main()
{
	//1
	unique_ptr<Date> today = make_unique<Date>();
	today->setDay(8);
	today->setMonth(6);
	today->setYear(2021);
	cout << *today;
	unique_ptr<Date> day = move(today);
	if (today)
		cout << *today << endl;
	else
		cout << "today nullptr" << endl;
	if (day)
		cout << *day << endl;
	else
		cout << "day nullptr" << endl;
	//2
	unique_ptr<Date> day1 = make_unique<Date>(20, 5, 2020);
	unique_ptr<Date> day2 = make_unique<Date>(15, 5, 2020);
	compare(day1, day2);
	swap(day1, day2);
	cout << "day1:" << *day1 << endl;
	cout << "day2:" << *day2 << endl;
	return 0;
}