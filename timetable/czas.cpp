
// czas.cpp
#include "czas.h"
#include <iostream>

using namespace std;

void time::set(int h, int m)
{
	if (h > 24 || h < 0 || m>60 || m < 0)
	{
		cout << "invalid paramets" << endl;
		hour = 0;
		minute = 0;
	}
	else
	{
		hour = h;
		minute = m;
	}
};

bool time::operator>(const time &tmp)const
{
	if (hour > tmp.hour)
		return true;
	if (hour == tmp.hour)
		if (minute > tmp.minute)
			return true;
	return false;
}

std::ostream & operator<<(std::ostream & out, time & c)
{
	out << c.hour << ":" << c.minute;
	return out;
}
