#include <iostream>
#include "subject.hpp"

std::ostream & operator<<(std::ostream & show, subject & s)
{
	show << s.name_of_subject << ", " << s.type_of_lesson << ", " << s.start_time << "-" << s.end_time;
	return show;
}

void subject::set(std::string name, int start_lesson_hour, int start_lesson_minute, int end_lesson_hour, int end_lesson_minute, std::string type)
{
	name_of_subject = name;
	type_of_lesson = type;
	start_time.set(start_lesson_hour, start_lesson_minute);
	end_time.set(end_lesson_hour, end_lesson_minute);
	if (start_time > end_time)
	{
		std::cout << "Invalid paramets for " << name_of_subject << ". Setting default values" << std::endl;
		start_time.set(8, 0);
		end_time.set(10, 0);
	}
}
