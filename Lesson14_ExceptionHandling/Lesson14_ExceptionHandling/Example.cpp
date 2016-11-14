#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

const string file_name = "data.txt";
const string file_2 = "data2.txt";

void read_scores(vector<int>& scores) throw (invalid_argument)
{
	ifstream data_file;
	ifstream data_two;
	int temp;

	data_file.open(file_name.c_str());

	if (data_file.fail())
		throw invalid_argument("no file exists " + file_name);

	while (data_file >> temp)
		scores.push_back(temp);




	data_two.open(file_2.c_str());

	if (data_two.fail())
		throw invalid_argument("no file exists " + file_2);

	while (data_two >> temp)
		scores.push_back(temp);

	data_file.close();
	data_two.close();
}

double find_average(const int sum, const int divisor) throw (runtime_error)
{
	if (!divisor)
		throw runtime_error("divisor is zero");
	return (sum / (double)divisor);
	//return 0;
}

void throwing_ftn() throw (runtime_error)
{
	throw runtime_error("something went wrong\n");
}

void memory_leak() throw (runtime_error)
{
	string* s = new string("hello");

	throwing_ftn();

	delete s;
}

void no_memory_leak() throw (runtime_error)
{
	string* s = new string("hello");

	try
	{
		throwing_ftn();
	}
	catch (...)
	{
		delete s;
		throw;
	}
	delete s;
}


int main()
{
	vector<int> scores;
	int sum = 0;

	try
	{
		read_scores(scores);
		for (int i = 0; i < scores.size(); ++i)
		{
			sum += scores[i];
		}
		cout << "avg = " << find_average(sum, scores.size()) << "\n";
	}
	catch (const invalid_argument& iae)
	{
		cout << "unable to read data: " << iae.what() << "\n";
		exit(1);
	}
	catch (const runtime_error& rte)
	{
		cout << "unable to compute average: " << rte.what() << "\n";
		exit(1);
	}

	for (int i = 0; i < scores.size(); ++i)
		cout << "score " << i << " = " << scores[i] << "\n";

	system("pause");
	return 0;
}