#pragma once
#include <iostream>
#include "data.hpp"
#include <string>
class person
{
	std::string name;
	std::string surname;
	date born;

public:
	std::string get_name()
	{
		return name;
	};
	std::string get_surname()
	{
		return surname;
	};
	void set(std::string tmp_name, std::string tmp_surname);
	person(std::string tmp_name = " ", std::string tmp_surname = " ", int d = 0, int m = 0, int y = 0) :
		date(d, m, y)
	{
		set(name, surname);
	};
	virtual std::ostream & out(std::ostream & tmp)
	{
		tmp << name << " " << surname <<  "\n" << born;
		return tmp;
	}
	friend std::ostream & operator<<(std::ostream &, person &);
};
