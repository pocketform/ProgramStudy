#include <iostream>

using namespace std;

//int& empty_reference;
//int& unnamed_reference = 5;

void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap_ref(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swap(char& x, char& y)
{
	char temp = x;
	x = y;
	y = temp;
}

void sorts(int arr[])
{
	for (int i = 1; i < 10; i++)
	{
		if (arr[i - 1] > arr[i])
		{
			swap_ref(arr[i - 1], arr[i]);
			for (int j = i - 1; j > 0; j--)
			{
				if (arr[j-1] > arr[j])
				{
					swap_ref(arr[j - 1], arr[j]);
				}
			}

		}
	}
}

int nums[10] = { 7, 5, 3, 6, 2, 4, 8, 9, 1, 0 };

int main()
{
	//int a, b;

	//cout << "Please type in a number" << "\n";
	//cin >> a;
	//cout << "Please type in another number" << "\n";
	//cin >> b;

	//cout << "before swap, a = " << a << " and b = " << b << "\n";
	//swap(a, b);
	//cout << "after swap (by value), a = " << a << " and b = " << b << "\n";
	//swap(&a, &b);
	//cout << "after swap by pointer reference, a = " << a << " and b = " << b << "\n";

	//swap_ref(a, b);
	//cout << "after swap using references, a = " << a << " and b = " << b << "\n";

//int x = 3, y = 4, z=8 ;
//	int& x_ref = x;
//	cout << x_ref << ' ' << &x_ref << ' ' << x << ' ' << &x << "\n";
//	x_ref = y;
//	cout << x_ref << ' ' << &x_ref << ' ' << x << ' ' << &x <<  ' ' << y << ' ' << &y << "\n";
//	x_ref = 8;
//	cout << x_ref << ' ' << &x_ref << ' ' << x << ' ' << &x <<  ' ' << y << ' ' << &y << z << ' ' << &z << "\n";

	//int& a_ref = a;

	//char a, b;

	//cout << "Please type in a number" << "\n";
	//cin >> a;
	//cout << "Please type in another number" << "\n";
	//cin >> b;

	//swap(a, b);

	//cout << "after swap using references, a = " << a << " and b = " << b << "\n";

	sorts(nums);

	for (int i = 0; i < 10; i++)
	{
		cout << nums[i] << endl;
	}

	int exit;

	cin >> exit;



	return 0;
}


