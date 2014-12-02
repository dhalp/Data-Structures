#include <iostream>
#include "dynamic_size_array_unsorted.h"

using namespace std;

bool equivalent_arrays(const int_array& a, const int_array& b)
{
	

	return false;
}

int main()
{
	int_array a;
	int_array b;
	init(a);
	init(b);
	cout << "Array a " << endl;
	print(a);
	cout << "Array b " << endl;
	print(b);
	if (equivalent_arrays(a, b))
		cout << "Same" << endl;
	else
		cout << "Different" << endl;
	add(a, 8);
	add(a, 8);
	add(b, 8);
	add(b, 8);
	cout << "Array a " << endl;
	print(a);
	cout << "Array b " << endl;
	print(b);
	if (equivalent_arrays(a, b))
		cout << "Same" << endl;
	else
		cout << "Different" << endl;
	remove(a, 8);
	cout << "Array a " << endl;
	print(a);
	cout << "Array b " << endl;
	print(b);
	if (equivalent_arrays(a, b))
		cout << "Same" << endl;
	else
		cout << "Different" << endl;
	add(b, 2);
	add(b, 9);
	cout << "Array a " << endl;
	print(a);
	cout << "Array b " << endl;
	print(b);
	if (equivalent_arrays(a, b))
		cout << "Same" << endl;
	else
		cout << "Different" << endl;
	
}
