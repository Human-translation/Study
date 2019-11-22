#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}


	Date(const Date& d)
		:_year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

	Date& operator=(const Date& d)
	{
		if (&d != this)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	bool LeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}

	int GetMonthDay(int year, int month)
	{
		int a[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int day = a[month - 1];
		if (month == 2 && LeapYear(year))
			day += 1;
		return day;
	}

	Date operator+=(int days)
	{
		_day += days;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
		}
		return *this;
	}


	Date operator-=(int days)
	{
		_day -= days;
		while (_day < 1)
		{
			_day += GetMonthDay(_year, _month);
			_month--;
			if (_month == 0)
			{
				_month = 12;
				_year--;
			}
		}
		return *this;
	}

	int operator-(const Date& d);

	Date& operator++()
	{
		return *this += 1;
	}

	Date operator++(int)
	{
		Date tmp = *this;
		*this += 1;
		return tmp;
	}

	Date& operator--()
	{
		return *this -= 1;
	}

	Date operator--(int)
	{
		Date tmp = *this;
		*this -= 1;
		return tmp;
	}

	bool operator>(const Date& d)const
	{
		return _year >= d._year
			&& _month >= d._month
			&& _day > d._day;
	}
	bool operator>=(const Date& d)const
	{
		return *this > d || *this == d;
	}

	bool operator<(const Date& d)const
	{
		return !(*this >= d);
	}

	bool operator<=(const Date& d)const
	{
		return !(*this > d);
	}

	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator!=(const Date& d)const
	{
		return !(*this == d);
	}

	int YEAR() const
	{
		return _year;
	}

	int MONTH() const
	{
		return _month;
	}

	int DAY() const
	{
		return _day;
	}
	
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin,  Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << " " << d._month << " " << d._day << endl;
	return _cout;
}

istream& operator>>(istream& _cin,  Date& d)
{
	_cin >> d._year >> d._month >> d._day;
	return _cin;
}

//void operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d.YEAR() << " " << d.MONTH() << " " << d.DAY() << endl;
//}


int main()
{
	Date time(2011,12,21);
	Date time2(2012, 12, 21);
	cin >> time;
	int x;
	x = time < time2;
	++time;
	cout << time<<endl;
	cout << time;
	system("pause");
	return 0;
}