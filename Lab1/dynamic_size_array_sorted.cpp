#include "dynamic_size_array_sorted.h"

using namespace std;


void init(int_array& arr)
{
	// STUB
}

void destr(int_array& arr)
{
	// STUB
}

void resize(int_array& arr)
{
	// STUB
}

void clear(int_array& arr)
{
	// STUB
}

void print(const int_array& arr)
{
	for (unsigned int i = 0; i < arr.count; ++i)
		cout << arr.data[i] << " ";
	cout << endl;
}

void add(int_array& arr, const int& payload)
{
	// STUB
}

bool remove(int_array& arr, const int& target)
{
	// STUB
	return true;
}

bool contains(const int_array& arr, const int& target)
{
	// STUB
	return true;
}

