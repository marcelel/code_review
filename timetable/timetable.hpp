#pragma once
#include <iostream>
#include <string>
#include "day_of_week.hpp"

class timetable
{
	day_of_week week[5] =
	{
		day_of_week("Monday"),
		day_of_week("Tuesday"),
		day_of_week("Wednesday"),
		day_of_week("Thursday"),
		day_of_week("Friday")
	};

public:
	void add(int, std::string, int, int, int, int, std::string type);
	friend std::ostream & operator<<(std::ostream &, timetable &);
};
