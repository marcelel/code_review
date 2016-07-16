#pragma once
#include <iostream>
class date
{
	int day, month, year;
	bool check(int d, int m, int y);

public:
	date(int d = 1, int m = 1, int y = 2016)
	{
		if (!set(d, m, y))
		{
			day = 1;
			month = 1;
			year = 2016;
		}
	}
	int get_month()
	{
		return month;
	}
	int get_day()
	{
		return day;
	}
	int get_year()
	{
		return year;
	}
	bool set(int d, int m, int y);
	date operator++();
	date operator++(int);
	bool operator<(const date &) const;
	friend bool operator>(const date &, const date &);
	friend std::ostream & operator<<(std::ostream & show, date & d);
};
