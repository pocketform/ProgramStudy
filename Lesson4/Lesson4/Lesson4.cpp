#include <iostream>

using namespace std;

void swap(int *a, int *b) 
	{
		int temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}

void implement(int *a)	
	{
		for (int i = 0; i < 5; i++)
		{			
			a++;
			cout << *a << endl;
			a++;
		}
	}

int main() {
	int in_one = 11;
	int in_two = 22;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10};

	implement(arr);

	cout << "The value of one is " << in_one << ", the value of two is " << in_two << endl;
	swap(in_one, in_two);
	cout << "The value of one is " << in_one << ", the value of two is " << in_two << endl;


	/**one = 11;
	*two = 22;*/

	/*int a = 100;

	cout << "Value in memory location a is " << a << "\n";

	cout << "Address of (the reference to) memory location a is " << &a << "\n";

	int *b = &a;

	cout << "Value in memory location pointed to by b is " << *b << "\n";


	cout << "Value in memory location b is " << b << "\n";
	cout << b << " should be the same as the memory location for a: " << &a << "\n";
	cout << "b is actually at memory location " << &b << endl;

	int** c;

	c = &b;
	cout << "c is now pointing to what b points to: " << **c << endl;

	cout << "c points to: " << *c << endl;

	cout << "c actually holds the value: " << c << endl;
	cout << c << " is the same value as b's memory location: " << &b << endl;
	cout << "c is actually at memory location " << &c << endl;

	cout << "c is eventually retrieving what is in memory location " << **&c << endl;
	cout << "the value of a is in memory location " << &a << endl;*/



	int x;
	cout << "Type in a numebr to finish" << "\n";
	cin >> x;



	return 0;
}


