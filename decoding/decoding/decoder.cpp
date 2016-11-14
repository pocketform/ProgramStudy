#include"way_decoding.h"

using namespace std;

int txt_n = 1;

bitset<4> my_r;

void loop_tow_way1()
{
	int xor1_1 = 0;
	int xor1_2 = xor1_1 + 1;
	int xor2_1;
	int xor2_2;
	int xor2_3;
	int xor2_4;

	txt_n = 1;


	//put 2 registers in xor1 and put 2 registers in xor2
	//get xor1_1
	while (xor1_1 < 4)
	{

		//cout << "the value of n is " << n << "\n";

		//get xor1_2
		while (xor1_2 < 4)
		{
			cout << "xor1_1 is " << xor1_1 << " and xor1_2 is " << xor1_2 << "\n";

			//get xor2_1
			for (xor2_1 = 0; xor2_1 < 4; xor2_1++)
			{

				if (xor2_1 != xor1_1 && xor2_1 != xor1_2)
				{
					//cout << "xor2_1 is " << xor2_1 << "\n";

					//get xor2_2
					for (xor2_2 = 0; xor2_2 < 4; xor2_2++)
					{

						if (xor2_2 != xor1_1 && xor2_2 != xor1_2 && xor2_2 != xor2_1)
						{
							cout << "xor2_2 is " << xor2_2 << "\n";


							cout << txt_n << "\n" << endl;
							txt_n++;
						}
					}
					break;
				}
			}
			xor1_2++;
		}

		xor1_1++;
		xor1_2 = xor1_1 + 1;

		//txt_n++;
	}
}

void get_output(int xor1_1, int xor1_2, int xor2_1, int xor2_2)
{

}

int main()
{
	//loop_tow_way1;

	int text = 0;

	int xor1_1 = 0;
	int xor1_2 = xor1_1 + 1;
	int xor2_1;
	int xor2_2;
	int xor2_3;
	int xor2_4;

	//get xor1_1
	while (xor1_1 < 4)
	{
		cout << "xor1_1 is " << xor1_1 << "\n";

		//get xor1_2
		while (xor1_2 < 4)
		{
			cout << "xor1_2 is " << xor1_2 << "\n";
			//get xor2_1
			for (xor2_1 = 0; xor2_1 < 4; xor2_1++)
			{


				if (xor2_1 != xor1_1 && xor2_1 != xor1_2)
				{
					cout << "xor2_1 is " << xor2_1 << "\n";

					//get xor2_2
					for (xor2_2 = 0; xor2_2 < 4; xor2_2++)
					{
						if (xor2_2 != xor1_1 && xor2_2 != xor1_2 && xor2_2 != xor2_1)
						{
							//XOR xor1(my_r[xor1_1], my_r[xor1_2]);
							//XOR xor2(my_r[xor2_1], my_r[xor2_2]);

							//bitset<1> output1 = xor1.do_xor_with_number(2);
							//bitset<1> output2 = xor2.do_xor_with_number(2);

							cout << "xor2_2 is " << xor2_2 << "\n";
							//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;
							txt_n++;
						}
					}
					break;
				}
			}
			xor1_2++;
		}

		xor1_1++;
		xor1_2 = xor1_1 + 1;

		//txt_n++;
	}

	//for (int i = 0; i < 2; i++)
	//{
	//	for (int j = 0; j < 2; j++)
	//	{
	//		for (int k = 0; k < 2; k++)
	//		{
	//			for (int n = 0; n < 2; n++)
	//			{
	//				text++;
	//				cout << "text is " << text << "\n";

	//				cout << "r & input is " << i << j << k << n << endl;

	//				//XOR xor1(my_r[xor1_1], my_r[xor1_2]);
	//				//XOR xor2(my_r[xor2_1], my_r[xor2_2]);

	//				XOR xor1(my_r[1], my_r[0]);
	//				XOR xor2(my_r[2], my_r[3]);

	//				bitset<1> output1 = xor1.do_xor_with_number(2);
	//				bitset<1> output2 = xor2.do_xor_with_number(2);

	//				cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;

	//			}
	//		}
	//	}
	//}

	//text of way_decoding 




	int exit;
	cin >> exit;

	return 0;
}