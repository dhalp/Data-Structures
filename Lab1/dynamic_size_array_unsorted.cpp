#include "dynamic_size_array_unsorted.h"

using namespace std;


void init(int_array& arr)
{
	arr.capacity = arr.DEFAULT_CAPACITY;
	arr.data = new int[arr.capacity];
	arr.count = 0;
}

void clear(int_array& arr)
{
	destr(arr);
	init(arr);
}

void destr(int_array& arr)
{
	delete [] arr.data;
	arr.count = 0;
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

bool contains(const int_array& arr, const int& target)
{
	for (int i = 0; i < arr.count; i++)
	{
		if (arr.data[i] == target)
		{
			return true;
		}
	}
	return false;
}

void resize(int_array& arr)
{
	int newCapacity = arr.capacity*2;

	int* bigger_array = new int[newCapacity];

	for (int i = 0; i < arr.capacity; i++)
	{
		bigger_array[i] = arr.data[i];
	}
	delete [] arr.data;

	arr.data = bigger_array;
}

void add(int_array& arr, const int& payload)
{
	if (arr.capacity == arr.count)
	{
		resize(arr);
	}
	arr.data[arr.count] = payload;
	arr.count++;
}

bool remove(int_array& arr, const int& target)
{
	for (int i = 0; i < arr.count; i++)
	{
		if (arr.data[i] == target)
		{
			arr.data[i] = arr.data[arr.count-1];
			arr.count--;
			return true;
		}
	}
	return false;
}