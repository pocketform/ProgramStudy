#include"xor_gate.h"


using namespace std;

class way_decoding
{
public:
	way_decoding(bitset<4> xor1, bitset<4> xor2);
	~way_decoding();
	void output_get(int xor1, int xor2);

private:
	int _0000;
	int _0001;
	int _0010;
	int _0011;
	int _0100;
	int _0101;
	int _0110;
	int _0111;
	int _1000;
	int _1001;
	int _1010;
	int _1011;
	int _1100;
	int _1101;
	int _1110;
	int _1111;

	int xor1_1;
	int xor1_2;
	int xor1_3;
	int xor1_4;

	int xor2_1;
	int xor2_2;
	int xor2_3;
	int xor2_4;

	bitset<4> d_r;
};

way_decoding::way_decoding(bitset<4> xor1, bitset<4> xor2)
{
	xor1_1 = xor1[0];
	xor1_2 = xor1[1];
	xor1_3 = xor1[2];
	xor1_4 = xor1[3];

	xor2_1 = xor1[0];
	xor2_2 = xor1[1];
	xor2_3 = xor1[2];
	xor2_4 = xor1[3];
}

way_decoding::~way_decoding()
{
}

void way_decoding::output_get(int xor1_n, int xor2_n)
{
	if (xor1_n == 2 && xor2_n == 2)
	{
		//		XOR xor1(xor1_1, xor1_2);
		//		XOR xor2(xor2_1, xor2_2);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{

						//bitset<1> output1 = xor1.do_xor_with_number(2);
						//bitset<1> output2 = xor2.do_xor_with_number(2);

						//	cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;

					}
				}
			}
		}
	}

	if (xor1_n == 3 && xor2_n == 2)
	{
		//XOR xor1(xor1_1, xor1_2, xor1_3);
		//XOR xor2(xor2_1, xor2_2);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{

						//bitset<1> output1 = xor1.do_xor_with_number(2);
						//bitset<1> output2 = xor2.do_xor_with_number(2);

						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;

					}
				}
			}
		}
	}

	if (xor1_n == 4 && xor2_n == 2)
	{
		//XOR xor1(xor1_1, xor1_2, xor1_3,xor1_4);
		//XOR xor2(xor2_1, xor2_2);

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					for (int n = 0; n < 2; n++)
					{

						//bitset<1> output1 = xor1.do_xor_with_number(2);
						//bitset<1> output2 = xor2.do_xor_with_number(2);

						//cout << "output1 is " << output1[0] << " output2 is " << output2[0] << endl;

					}
				}
			}
		}
	}



}