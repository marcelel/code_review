/* Szablon klasy bedacej tablica o zmiennym rozmiarze zawierajaca elementy typu T. Zaimplementowac metody:
- dodawanie elementu na koncu
- usuwanie 
- operator przypisania */

#pragma once
#include <iostream>

template<class T>
class array_T
{
	T* arr;
	int counter;
public:	
	array_T() :
		counter(0),
		arr(nullptr)
	{}
	~array_T()
	{
		if (counter != 0)
			delete[] arr;
	}
	void add(T &);
	bool del(int);
	array_T<T>& operator=(const array_T<T> & tmp)
	{
		if (tmp.counter != 0)
		{
			if (arr != nullptr)
				delete[] arr;
			counter = tmp.counter;
			arr = new T[counter];
			for (int i = 0; i < counter; i++)
				arr[i] = tmp.arr[i];
		}
		return *this;
	}
	friend std::ostream & operator<<(std::ostream & output, const array_T<T> & tmp)
	{
		for (int i = 0; i < tmp.counter; i++)
			output << tmp.arr[i] << std::endl;
		return output;
	}
};


template <class T>
void array_T<T>::add(T & added)
{
	if (counter == 0)
	{
		arr = new T[++counter];
		arr[0] = added;
	}
	else
	{
		T* tmp = new T[++counter];
		for (int i = 0; i < counter - 1; i++)
			tmp[i] = arr[i];
		tmp[counter - 1] = added;
		delete[] arr;
		arr = tmp;
	}
}

template <class T>
bool array_T<T>::del(int deleted)
{
	if (deleted < 0 || deleted >= counter)
		return false;
	else
	{
		T* tmp = new T[--counter];
		for (int i = 0; i < deleted; i++)
			tmp[i] = arr[i];
		for (int i = deleted; i < counter; i++)
			tmp[i] = arr[i + 1];
		delete[] arr;
		arr = tmp;
	}
}





