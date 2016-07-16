#include "student.hpp"

void student::set(long int number)
{
    if (number < 100000 || number > 1000000)
    {
        std::cout << "invalid paramet\n";
		album_number = 123456;
    }
    else
		album_number = number;
};

std::ostream & operator<<(std::ostream & show, student & s)
{
    return s.out(show);
};

