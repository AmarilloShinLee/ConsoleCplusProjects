#include <iostream>
#include <string>
#include <iomanip>
#include "ATMSystem.h"

using namespace std;

string choiceValidation_ATM();
string balanceValidation_ATM();
bool checkInput_ATM(string input);

int ATMSystemMain()
{
    bool loopSwitch = true;
    bool firstInnerLoopSwitch = true;
    bool secondInnerLoopSwitch = true;
    double balance = 5000;
    double withdrawNumber, depositNumber, formerBalance;
    string userInput;
    string modeLabel = "\nMode:";

	cout << "\t\tWelcome to Banks Program 101\n";

    while (loopSwitch == true)
    {
        //Choosing ATM options
        do
        {
            secondInnerLoopSwitch = true;

            cout
                << "\nWhat do you wish to do?\n"
                << "\tA. Balance Inquiry\n"
                << "\tB. Withdraw\n"
                << "\tC. Deposit\n"
                << "\tD. Exit\n";
            userInput = choiceValidation_ATM();

            if (toupper(userInput[0]) == 'A')
            {
                cout
                    << modeLabel << "\tBalance Inquiry\n"
                    << "Balance Total:" << right << setw(23) << setfill(' ') << balance << endl;

                firstInnerLoopSwitch = false;
            }
            else if (toupper(userInput[0]) == 'B')
            {
                cout
                    << modeLabel << "\tWithdrawal\n"
                    << "How much do you want to Withdraw?\n";
                withdrawNumber = stod(balanceValidation_ATM());

                formerBalance = balance;
                balance -= withdrawNumber;

                if (balance < 0)
                    cout
                    << "\nUnable to Withdraw!"
                    << "\nYour Current Balance:" << setfill(' ') << setw(10) << left << formerBalance
                    << "\nSupposed Withdraw Amount:" << setfill(' ') << setw(5) << left << withdrawNumber << endl;
                else
                    cout
                    << "\nFormer Balance Total:" << right << setw(16) << setfill(' ')  << formerBalance
                    << "\nWithdraw Amount:" << right << setw(20) << setfill(' ') << withdrawNumber
                    << "\nCurrent Balance Total:" << right << setw(15) << setfill(' ') << balance << endl;

                firstInnerLoopSwitch = false;
            }
            else if (toupper(userInput[0]) == 'C')
            {
                cout
                    << modeLabel << "\tDeposit\n"
                    << "How much do you want to Deposit?\n";
                depositNumber = stod(balanceValidation_ATM());

                formerBalance = balance;
                balance += depositNumber;

                cout
                    << "\nFormer Balance Total:" << right << setw(16) << setfill(' ') << formerBalance
                    << "\nDeposit Amount:" << right << setw(21) << setfill(' ') << depositNumber
                    << "\nCurrent Balance Total:" << right << setw(15) << setfill(' ') << balance << endl;

                firstInnerLoopSwitch = false;
            }
            else if (toupper(userInput[0]) == 'D')
            {
                cout << "\nThank you for using Bank Program 101. Have a nice day!\n";

                firstInnerLoopSwitch = false;
                secondInnerLoopSwitch = false;
                loopSwitch = false;
            }
            else
                cout << "Input is not part of the choices. Please try again.";
        } while (firstInnerLoopSwitch == true);

        //Continuation
        while (secondInnerLoopSwitch == true)
        {
            cout
                << "\nDo you wish for another transaction?\n"
                << "\tYes (Y)\n"
                << "\tNo (N)\n";
            userInput = choiceValidation_ATM();

            if (toupper(userInput[0]) == 'Y')
            {
                secondInnerLoopSwitch = false;
                firstInnerLoopSwitch = true;
            }
            else if (toupper(userInput[0]) == 'N')
            {
                cout << "\nThank you for using Bank Program 101. Have a nice day!\n";

                secondInnerLoopSwitch = false;
                loopSwitch = false;
            }
            else
                cout << "Input is not part of the choices. Please try again.";
        }
    }

    cout << endl;

	return 0;
}

string choiceValidation_ATM()
{
    bool validationMistake = true;
    string input;

    while (validationMistake == true)
    {
        cout << "Input: ";
        getline(cin, input);

        if (checkInput_ATM(input))
            cout << "\tInput is not a letter. Please try again: ";
        else
            validationMistake = false;
    }

    return input;
}
string balanceValidation_ATM()
{
    bool validationMistake = true;
    string input;

    while (validationMistake == true)
    {
        cout << "Input: ";
        getline(cin, input);

        if (checkInput_ATM(input))
            validationMistake = false;
        else
            cout << "\tInput is not a number. Please try again: ";
    }

    return input;

}
bool checkInput_ATM(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]) == false)
            return false;

        return true;
    }
}