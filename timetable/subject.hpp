#pragma once
#include "czas.h"
#include <iostream>
#include <string>

class subject
{
	std::string name_of_subject;
	czas start_time;
	czas end_time;
	std::string type_of_lesson;

public:
	subject(std::string name = " ", int start_lesson_hour = 0, int start_lesson_minute = 0, int end_lesson_hour = 0, int end_lesson_minute = 0, std::string type = " ")
	{
		set(name, start_lesson_hour, start_lesson_minute, end_lesson_hour, end_lesson_minute, type);
	};
	void set(std::string, int, int, int, int, std::string);
	friend std::ostream & operator<<(std::ostream &, subject &);
};
