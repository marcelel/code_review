#pragma once
#include <iostream>
#include <string>
#include "subject.hpp"

class day_of_week
{
	std::string name;
	subject* subject_list;
	int counter;

public:
	day_of_week(std::string day_tmp = " ") :
		counter(0),
		name(day_tmp)
	{
		subject_list = new subject[1];
	}
	day_of_week(const day_of_week&);
	~day_of_week()
	{
		delete[] subject_list;
	}
	void add_subject(std::string, int, int, int, int, std::string);
	day_of_week & operator =(const day_of_week &);
	friend std::ostream & operator<<(std::ostream &, day_of_week &);
};
