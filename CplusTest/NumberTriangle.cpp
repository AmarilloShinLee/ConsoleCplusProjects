#include "NumberTriangle.h"
#include <iostream>
#include <algorithm>

using namespace std;

int GetEachDigit(int number)
{
	int count = 0;
	while (number)
	{
		number /= 10;
		count++;
	}
	return count;
}

void NumberTriangle()
{
	int number;
	int numArray[] = { 1, 2, 3, 4, 5, 6 };
	const int numArraySize = sizeof(numArray) / sizeof(numArray[0]);
	int maxCounts[numArraySize];

	for (int counts = 0; counts <= numArraySize - 1; counts++)
	{
		maxCounts[counts] = counts;
	}

	reverse(maxCounts, maxCounts + numArraySize);

	for (int i = numArraySize; i >= 0; i--)
	{	
		for (int j = 0; j <= i; j++)
		{

			//if (numSpecific < 0 || numSpecific > 32767)
			//{
			//	continue;
			//}
			
			if (j == 0 && i == numArraySize)
			{
				cout << 0 << "\t";
				continue;
			}
			
			if (i == numArraySize)
			{
				cout << numArray[j - 1] << "\t";
			}
			else
			{
				cout << numArray[j + maxCounts[i]] << "\t";
			}
		}

		cout << endl;
	}
}