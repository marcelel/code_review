#include <iostream>
#include "timetable.hpp"

void timetable::add(int day, std::string name, int start_lesson_hour, int start_lesson_minute, int end_lesson_hour, int end_lesson_minute, std::string type)
{
	if (day < 0 || day > 4)
		std::cout << "Day not found" << std::endl;
	else
		week[day].add_subject(name, start_lesson_hour, start_lesson_minute, end_lesson_hour, end_lesson_minute, type);
}

std::ostream & operator<<(std::ostream & out, timetable & table)
{
	for (int i = 0; i < 5; i++)
		out << table.week[i] << "\n";
	return out;
}

