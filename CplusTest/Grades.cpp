#include "Grades.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

char gradeChecker(float average, int scores[])
{
	char grade;
	if (average >= 90)
		grade = 'A';
	else if (average >= 70 && average < 90) 
	{
		if (scores[2] > 90)
			grade = 'A';
		else
			grade = 'B';
	}
	else if (average >= 50 && average < 70)
	{
		float secondAverage = (scores[1] + scores[2]) / 2;
		if (secondAverage > 70)
			grade = 'C';
		else
			grade = 'D';
	}
	else
		grade = 'F';

	return grade;
}

float averageCalculator(int scores[], int scoresArraySize)
{
	int sum = 0;
	float average;

	for (int j = 0; j <= scoresArraySize - 1; j++)
		sum += scores[j];

	average = (float)sum / (float)scoresArraySize;
	return average;
}

void gradeChecking()
{
	int scores[3];
	int scoresArraySize = sizeof(scores) / sizeof(scores[0]);
	float average;
	string studentName;
	char grade;

	cout << "Enter name of student: ";
	getline(cin, studentName);

	cout << "Enter 3 scores: \n";
	for (int i = 0; i <= scoresArraySize - 1; i++) 
	{
		cout << "\tScore " << i + 1 << ": ";
		cin >> scores[i];
		if (scores[i] < 0 || scores[i] > 100)
		{
			cout << "\t\tNumber is too big or too small. Try again.\n";
			cin.ignore();
			cout << "\tScore " << i + 1 << ": ";
			cin >> scores[i];
		}
		while (cin.fail())
		{
			cout << "\t\tNumber is not a numerical number. Try again.\n";
			cin.clear();
			cin.ignore();
			cout << "\tScore " << i + 1 << ": ";
			cin >> scores[i];
		}
	}

	average = averageCalculator(scores, scoresArraySize);
	grade = gradeChecker(average, scores);

	cout << studentName << "'s Grade is : " << grade;
	cout << endl;
}

