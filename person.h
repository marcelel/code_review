#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class person
{
public:
	string name;
	string surname;
	string pesel;
};

class LO
{
	vector<person> arr;

public:
	void add(const person & tmp)
	{
		bool tmp_pesel = true;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].pesel == tmp.pesel)
			{
				arr[i].name = tmp.name;
				arr[i].surname = tmp.surname;
				tmp_pesel = false;
			}
		}
		if (tmp_pesel)
			arr.push_back(tmp);
	}
	void search(LO & score, const char * txt)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].pesel == txt || arr[i].name == txt || arr[i].surname == txt)
			{
				score.add(arr[i]);
			}
		}
	}
	bool operator==(const LO & tmp)
	{
		if (arr.size() != tmp.arr.size())
		{
			return false;
		}
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i].name != tmp.arr[i].name || arr[i].surname != tmp.arr[i].surname || arr[i].pesel != tmp.arr[i].pesel)
				return false;
		}
		return true;
	}
	friend LO operator*(const LO & left, const LO & right)
	{
		LO tmp;
		for (int i = 0; i < left.arr.size(); i++)
			for (int j = 0; j < right.arr.size(); j++)
			{
				if (left.arr[i].name == right.arr[j].name && left.arr[i].surname == right.arr[j].surname && left.arr[i].pesel == right.arr[j].pesel)
				{
					tmp.add(left.arr[i]);
				}
			}
		return tmp;
	}
};


