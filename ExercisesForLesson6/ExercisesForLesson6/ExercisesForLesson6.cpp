#include <iostream>
using namespace std;

namespace some_namespace
{
	void some_function()
	{ 
		int a = 400;
		char letter = 'b';
		cout << a << " " << letter << endl;

	}	
}

namespace some_other_namespace
{
	void some_function()
	{
		int a = 400;
		char letter = 'b';
		cout << a << " " << letter << endl;
	}
}





int global_variable = 50;



int main()
{

	//cout << "global variable contains the value " << global_variable << "\n";

	//int a = 100;
	//int* b;

	//{

	//	int a = 200;

	//	cout << "the value in a is " << a << "\n";

	//	int* local_ptr = new int(300);

	//	b = local_ptr;

	//}

	//cout << "the value in a is " << a << "\n";

	//cout << "the value pointed to by 'b' is " << *b << "\n";
	//delete b;
	//b = NULL;

	//std::cout << "output some data" << "\n";

	some_namespace::some_function();

	some_other_namespace::some_function();

	int a;

	cin >> a;

	return 0;
}