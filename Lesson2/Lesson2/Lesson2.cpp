#include <iostream>

using namespace std;

//TODO : product function
int product(int x, int y)
	{
		return x * y ;
	}

//TODO : quotient function
double quotient(double x, int y) 
	{
		return x / y;
	}

//TODO : calculator program
double Calculator_Program(double x, double y, char a) 
	{

		switch (a)
		{
		case '+' :
			return x + y;
			break;

		case '-':
			return x - y;
			break;

		case '*':
			return x*y;
			break;

		case '/':
			return x / y;
			break;
				 
		default:
			return 0;
			break;
		}
	}

int add(int x, int y) {

	return x + y;
}

int minus(int x, int y);

int main() {

	int a, b, c, exit;
	char o;

	cout << "Please type in a number" << "\n";
	cin >> a;

	cout << "Please type in another number" << "\n";
	cin >> b;

	cout << "Please type a operator from \"+,-,*,/\" \n";
	cin >> o;

	cout << "you get a number " << Calculator_Program(a, b, o) << "\n";
	//c = add(a, b);
	//cout << a << '+' << b << '=' << c << "\n";
	//cout << a << '+' << b << '=' << add(a, b) << "\n";
	//cout << product(a, b) <<"\n" ;
	/*cout << quotient(a, b) << "\n";*/

	cout << "enter another number to exit" << "\n";

	cin >> exit;

	return 0;
}

int minus(int x, int y) {

	return x - y;
}


