#include <iostream>

using namespace std;

int add(int x, int y) {
	return x + y;
}

int fac(int x) {

	int facSum = 1;

	for (int count = x; count > 0; count--)
		facSum = facSum * count;

	return facSum;
}

//TODO : Exercises 1
bool Compare(int x)
	{
		if (x >= 0)
			return true;
		else return false;
	}

//TODO : Exercises 2
void GetNegative() 
	{
		int GetN;
		while (true)
		{
			cout << "Please type a number. \n";
			cin >> GetN;
			if (Compare(GetN))
			{
				cout << "You get a positive number or zero. \n";
			}

			else
			{
				cout << "You get a negtive number. \n";
				break;
			}
			

		}
	}

//TODO : Exercises 3
void Recursion(int x, int sum)	
	{
		cout << "Please type a number. \n";
		cin >> x;
		sum = fac(x) + sum;
		cout << "sum is " << sum << "\n";

		if (sum <= 2000)
			Recursion(x, sum);
		else return; 
	}

int main() {
	int end;
	int x = 0;
	int y = 0;

	//int total = 0;
	//cout << "Please enter numbers, will finish if sum of factorals exceeds 2000" << "\n";

	//while (total <= 2000) {
	//	cin >> x;
	//	total = add(fac(x), total);
	//	cout << "Now sum is " << total << "\n";
	//}

	//cout << "The total is " << total << "\n";

	//if (total > 3000)
	//	cout << "you overshot by a lot!" << "\n";
	//else {
	//	cout << "You just went over" << "\n";
	//	cout << "Only over by " << total - 2000 << "\n";
	//}

	//TODO : For Exercises 1
	//a = -1;
	//cout << "The bool is " << Compare(a) << "\n";
	//cout << "Please type a number \n";
	//cin >> a;
	//cout << "The bool is " << Compare(a) << "\n";

	//TODO : For Exercises 2
	/*GetNegative();*/

	Recursion(x, y);

	cout << "enter a number to exit" << "\n";

	cin >> end;

	return 0;
}


