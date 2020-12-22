#include "testArea.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void OutputTest()
{
	string numbers[] = { "22", "60" };

	cout << numbers[0] << " : " << numbers[1] << endl;

	if (stoi(numbers[1]) >= 60)
	{
		int numberContain1 = stoi(numbers[0]);
		int numberContain2 = stoi(numbers[1]) % 60;

		numbers[0] = to_string(++numberContain1);
		numbers[1] = to_string(numberContain2);
	}

	cout << numbers[0] << " : " << numbers[1] << endl;
}