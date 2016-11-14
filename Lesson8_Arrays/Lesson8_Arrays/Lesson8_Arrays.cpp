#include <iostream>
#include <string.h>

using namespace std;

float calc_avg(const int* arr, const int val)
{
	int sum = 0;

	for (int i = 0; i < val; ++i)
		sum += arr[i];

	return (sum / (float)val);
}

float calc_avg(const int* arr, const int val);


void print_arr(const char arr[])
{
	//std::string str = arr;
	//for (char & e : str)
	//{
	//	cout << e;
	//}

	for (char i = 0; i < 7; i++)
	{
		cout << arr[i];
	}

	cout << '\n';
}


int main(void)
{
	//const int CONST_VALUE = 3;
	//float ave;

	//// stack based 1-d arrays
	//int array_nums[CONST_VALUE] = { 2, 4, 5 };



	//// print out the first element
	//cout << "value at index 0 is " << array_nums[0] << "\n";

	////stack based 2-d arrays
	//char naughts_n_xs[3][3];

	//// set the middle square to x
	//naughts_n_xs[1][1] = 'X';

	////arrays on the heap 1-d
	//int* sum = new int[CONST_VALUE];

	//for (int i = 0; i < CONST_VALUE; ++i)
	//{
	//	cout << "enter a value...\n";
	//	cin >> sum[i];
	//}

	//ave = calc_avg(sum, CONST_VALUE);

	//cout << "the average is " << ave << "\n";

	//delete[] sum;



//Exercises 1


	char array_name[7] = { 'C','h','e','n',' ','M','o' };

	print_arr(array_name);

	//Exercises2
	char* first_name = new char[4];
	char* last_name = new char[2];

	for (char i = 0; i < 4; i++)
	{
		first_name[i] = array_name[i];
	}

	for (char i = 0; i < 2; i++)
	{
		last_name[i] = array_name[i + 5];
	}

	delete first_name;
	first_name = NULL;

	delete last_name;
	last_name = NULL;

	int exit;

	cin >> exit;

	return 0;
}




