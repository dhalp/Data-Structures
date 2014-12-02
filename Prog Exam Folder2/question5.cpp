#include <iostream>
#include <ctime>

using namespace std;

int array_sum_iterative(const int*& arr, const unsigned int& size)
{
	//This starts at 0 because we have no values yet
	int answer = 0;
	// i starts at 0 because its a counter and we start indexing arrays at 0
	unsigned int i = 0;
	//This iterates through the whole array
	while (i < size)
	{
		//Every time it goes deaper into the array it adds the data to the running total
		answer = answer + arr[i];
		//This progresses us through the array
		i++;
	}
	return answer;
}

int array_sum_recursive(const int* arr, const unsigned int& size)
{
	//this checks if the array is empty
	if (size == 0)
	{
		return 0;
	}
	//if the array is not empty it will return the formula below
	//the formula recalls the sum function with a smaller size (essentially the iterator in this case)
	//this essentially goes down layers till it starts at the innitial value
	//then this climbs out each layar adding the running total as the returned value
	//Below was used for debugging
	//cout<<"size is: "<<size<<endl;
	//cout<< arr[0] + array_sum_recursive(arr+1, size-1)<<endl;
	return arr[0] + array_sum_recursive(arr+1, size-1);
}

void array_print(const int* arr, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	srand(time(nullptr));	// this line is unimportant for your job..

	int* arr = nullptr;
	unsigned int size = 0;
	
	cout << "Array arr: " << endl;
	const int* const_arr = arr;
	array_print(const_arr, size);
	cout << "Sum of array arr with loop: " << array_sum_iterative(const_arr, size) << endl;
	cout << "Sum of array arr with recursion: " << array_sum_recursive(const_arr, size) << endl;
	cout << "These numbers should eventually be the same..." << endl;
	
	arr = new int[10];
	for (unsigned int i = 0; i < 10; ++i)
	{
		arr[i] = i;
		size++;
	}	
	
	cout << "Array arr: " << endl;
	const_arr = arr;
	array_print(const_arr, size);
	cout << "Sum of array arr with loop: " << array_sum_iterative(const_arr, size) << endl;
	cout << "Sum of array arr with recursion: " << array_sum_recursive(const_arr, size) << endl;
	cout << "These numbers should eventually be the same..." << endl;

	size = 0;
	for (unsigned int i = 0; i < 10; ++i)
	{
		arr[i] = rand() % 100 + 1;	// random numbers generated here for you
		size++;
	}	
	cout << "Array arr: " << endl;
	const_arr = arr;
	array_print(const_arr, size);
	cout << "Sum of array arr with loop: " << array_sum_iterative(const_arr, size) << endl;
	cout << "Sum of array arr with recursion: " << array_sum_recursive(const_arr, size) << endl;
	cout << "These numbers should eventually be the same..." << endl;


	delete [] arr;
}
