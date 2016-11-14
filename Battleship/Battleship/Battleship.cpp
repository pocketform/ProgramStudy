// Battleship.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	bool ground[5][5];
	int to_guess;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			ground[i][j] = false;
		}
	}

	ground[0][0] = true;

	while (true)
	{
		cout << "Please type a number \"from 0 to 24\" \n";
		cin >> to_guess;

		int i, j;

		i = to_guess / 5;
		j = to_guess % 5;

		if (ground[i][j])
		{
			break;
		}
	}


    return 0;
}

