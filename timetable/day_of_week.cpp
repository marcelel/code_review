#include <iostream>
#include "day_of_week.hpp"

day_of_week::day_of_week(const day_of_week& tmp)
{
	name = tmp.name;
	counter = tmp.counter;
	if(tmp.counter == 0)
		subject_list = new subject[1];
	else
	{
		subject_list = new subject[counter];
		for (int i = 0; i < this->counter; i++)
			subject_list[i] = tmp.subject_list[i];
	}
}

void day_of_week::add_subject(std::string name, int start_lesson_hour, int start_lesson_minute, int end_lesson_hour, int end_lesson_minute, std::string type)
{
	if (counter == 0)
	{
		subject_list[0].set(name, start_lesson_hour, start_lesson_minute, end_lesson_hour, end_lesson_minute, type);
		counter++;
	}
	else
	{
		counter++;
		subject* subject_list_tmp = new subject[counter];
		for (int i = 0; i < counter - 1; i++)
			subject_list_tmp[i] = subject_list[i];
		subject_list_tmp[counter - 1].set(name, start_lesson_hour, start_lesson_minute, end_lesson_hour, end_lesson_minute, type);
		delete[] subject_list;
		subject_list = subject_list_tmp;
	}
}

day_of_week & day_of_week::operator =(const day_of_week & tmp)
{
	if (tmp.counter != 0)
	{
		counter = tmp.counter;
		delete[] subject_list;
		subject_list = new subject[counter];
		for (int i = 0; i<this->counter; i++)
			subject_list[i] = tmp.subject_list[i];
	}
	return *this;
}

std::ostream & operator<<(std::ostream & out, day_of_week & day)
{
	out << day.name << ": \n";
	for (int i = 0; i < day.counter; i++)
		out << day.subject_list[i] << "\n";
	return out;
}
