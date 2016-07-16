#pragma once
//#include "stdafx.h"
#include "osoba.hpp"
#include "timetable.hpp"
#include <iostream>

class student : public virtual person
{
	long int album_number;
	timetable *plan;

protected:
	student(long int album_tmp)
	{
		album_number = album_tmp;
	}

public:
	void set_plan(timetable * tmp)
	{
		plan = tmp;
	}
    long int get()
    {
        return album_number;
    }
    void set(long int number);
	student() :
		album_number(0),
		plan(NULL),
		person("Adam", "Nowak", 1, 05, 1996)
    {}
    student(std::string name, std::string surname, int d, int m, int y, int nr):
		person(name, surname, d, m, y),
		plan(NULL)
    {
        set(nr);
    };
    std::ostream & out(std::ostream & tmp)
	{
        if (plan)
            tmp << static_cast<person&>(*this) << "\nnumer albumu: " << album_number << "\n" << *plan;
        else
            tmp << static_cast<person&>(*this) << "\nnumer albumu: " << album_number;
        return tmp;
	}
    friend std::ostream & operator<<(std::ostream &, student &);
};
