// czas.hpp

#pragma once
#include <iostream>

class time
{
	int hour;
	int minute;

public:
	int get_hour()
	{
		return hour;
	};
	int get_minute()
	{
		return minute;
	};
	void set(int h, int m);
	bool operator>(const time &) const;
	friend std::ostream & operator<<(std::ostream &, time &);
};

