#include <iostream>
#include <string>
#include "BasicCalculator.h"

using namespace std;

string inputValidation_BasicCalc();
bool checkInput_BasicCalc(string input);

int BasicCalculatorMain()
{
    int userInput, firstNumber, secondNumber, remainder, results;
    bool loopSwitch = true;

    cout << "\t\tWelcome to Basic Calculator with Conversion!\n\n";

    cout << "Enter The First Number: ";
    firstNumber = stoi(inputValidation_BasicCalc());

    cout << "Enter the Second Number: ";
    secondNumber = stoi(inputValidation_BasicCalc());

    cout
        << "\nChoose an operation:\n"
        << "\t1. Addition\n"
        << "\t2. Subtraction\n"
        << "\t3. Multiplication\n"
        << "\t4. Division\n";

    while (loopSwitch == true)
    {
        cout << "User Input: ";
        userInput = stoi(inputValidation_BasicCalc());

        cout << endl;

        switch (userInput)
        {
        case 1:
            results = firstNumber + secondNumber;
            cout << "Sum: " << results;
            loopSwitch = false;
            break;
        case 2:
            results = firstNumber - secondNumber;
            cout << "Differece: " << results;
            loopSwitch = false;
            break;
        case 3:
            results = firstNumber * secondNumber;
            cout << "Product: " << results;
            loopSwitch = false;
            break;
        case 4:
            results = firstNumber + secondNumber;
            remainder = firstNumber % secondNumber;

            cout << "Quotient: " << results;
            if (remainder != 0)
                cout << "\nRemainder: " << remainder;

            loopSwitch = false;
            break;
        default:
            cout << "\tInput is not part of the choices. Please try again.\n";
            break;
        }
    }

    cout << endl;
    
	return 0;
}

string inputValidation_BasicCalc()
{
    bool validationMistake = true;
    string input;

    while (validationMistake == true)
    {
        getline(cin, input);

        if (checkInput_BasicCalc(input))
            validationMistake = false;
        else
            cout << "\tInput is not a number. Please try again: ";
    }

    return input;
}
bool checkInput_BasicCalc(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == false)
            return false;
        
        return true;
    }
}