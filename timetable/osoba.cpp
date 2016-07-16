#include "osoba.hpp"

using namespace std;

void person::set(string tmp_name, string tmp_surname)
{
	bool tmp1 = true;
	for (int i = 0; i < tmp_name.length(); i++)
	{
		if ((tmp_name.at(i) < 65) || (tmp_name.at(i) > 90 && tmp_name.at(i) < 97) || (tmp_name.at(i) > 122))
		{
			cout << "invalid paramets" << endl;
			tmp1 = false;
			break;
		}
	};
	if (tmp1)
	{
		name = tmp_name;
		for (int i = 0; i < name.length(); i++)
			name[i] = tolower(name[i]);
		name[0] = toupper(name[0]);
	};
	bool tmp2 = true;
	for (int i = 0; i < tmp_surname.length(); i++)
	{
		if ((tmp_surname.at(i) < 65 && tmp_surname.at(i) != 45) || (tmp_surname.at(i) > 90 && tmp_surname.at(i) < 97) || (tmp_surname.at(i) > 122))
		{
			cout << "invalid paramets" << endl;
			tmp2 = false;
			break;
		}
	};
	if (tmp2)
	{
		surname = tmp_surname;
		for (int i = 0; i < tmp_surname.length(); i++)
			surname[i] = tolower(surname[i]);
		for (int i = 0; i < tmp_surname.length(); i++)
			if (surname.at(i) == 45)
				surname[i + 1] = toupper(surname[i + 1]);
		surname[0] = toupper(surname[0]);
	}
}

std::ostream & operator<<(std::ostream & show, person & o)
{
	return o.out(show);
}
