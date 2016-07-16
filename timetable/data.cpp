#include <iostream>
#include "data.hpp"

bool date::check(int d, int m, int y)
{
	if (y < 1)
		return false;
	if (m < 1 || m > 12)
		return false;
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (d > 31 || d < 1)
			return false;
		else
			break;
	case 2:
		if (d > 29 || d < 1)
			return false;
		else
			break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (d > 30 || d < 1)
			return false;
	}
	return true;
};

bool date::set(int d, int m, int y)
{
	if (check(d, m, y))
	{
		day = d;
		month = m;
		year = y;
		return true;
	}
	else
		return false;
}

date date::operator++()
{
	if (!set(++day, month, year))
	{
		++month;
		day = 1;
	}
	if (!set(day, month, year))
	{
		++year;
		month = 1;
		return *this;
	}
	return *this;
}

date date::operator++(int)
{
	date copy(*this);
	if (!set(day + 1, month, year))
	{
		month += 1;
		day = 1;
	}
	if (!set(day, month, year))
	{
		year += 1;
		month = 1;
		return copy;
	}
	return copy;
}

bool date::operator<(const date &wartosc)const
{
	if (year<wartosc.year)
		return true;
	if (year == wartosc.year)
		if (month<wartosc.month)
			return true;
	if (month == wartosc.month)
		if (day<wartosc.day)
			return true;
		else
			return false;
	if (month >= wartosc.month)
		return false;
	if (year >= wartosc.year)
		return false;
}

bool operator>(const date & obj1, const date & obj2)
{
	if (obj1.year>obj2.year)
		return true;
	if (obj1.year == obj2.year)
		if (obj1.month>obj2.month)
			return true;
	if (obj1.month == obj2.month)
		if (obj1.day>obj2.day)
			return true;
		else
			return false;
	if (obj1.month <= obj2.month)
		return false;
	if (obj1.year <= obj2.year)
		return false;
}

std::ostream & operator<<(std::ostream & show, date & d)
{
	show << d.day << "." << d.month << "." << d.year;
	return show;
}

