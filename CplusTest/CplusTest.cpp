#include <iostream>
//#include "SessionCounts.h"
//#include "ConversionPartTwo.h"
//#include "Fibonacci.h"
//#include "NumberTriangle.h"
//#include "Grades.h"
//#include "AreaOfCircle.h"
//#include "ThreeNumbers.h"
//#include "TheCalculator.h"
//#include "ParkingLotConsole.h"
//#include "testArea.h"
//#include "BankLoanProject.h"
#include "BasicCalculator.h"
#include "ATMSystem.h"
#include "GuessingGame.h"

using namespace std;

enum Classes 
{ 
    basicCalculator,
	atmSystem,
	guessingGame
};

int main()
{
    Classes classInput = guessingGame;

	switch (classInput)
	{
	case basicCalculator:
			return BasicCalculatorMain();
		break;
	case atmSystem:
			return ATMSystemMain();
		break;
	case guessingGame:
			return GuessingGameMain();
		break;
	default:
			return 0;
		break;
	}
}
