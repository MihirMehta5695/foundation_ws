/*

3. Guessing Bot

Write a C++ program that calculates a random number 1 through 100. 
The program then asks the user to guess the number. 
If the user guesses too high or too low then the program should output ”guess higher” or ”guess lower” accordingly.
The program must let the user continue to guess until the user correctly guesses the number.

Modification :
•   Modify the program to output how many guesses it took the user to correctly guess the right number.

•   Modify the program so that instead of the user guessing a number the bot came up with, the bot guesses the number that the user has secretly decided.
    The user must tell the bot whether it should guess higher or lower.
    The bot should randomly but not blindly. 
    The bot should improve its guesses based on the feedback provided by the user.

•   Modify the program so that no matter what number the user thinks between 1 and 100, the bot can guess it in 7 or less guesses. 
    (HINT : Here the bot will not be guessing randomly.)

*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*
This function runs the basic program with modification 1 as stated in problem statement!
*/
void modification_1()
{
    int guess, tries = 0;
    bool isGuessCorrect = false;

    // This generates a random number between 1 and 100!
    int n = rand() % 100 + 1;

    cout << endl;
    while (!isGuessCorrect)
    {
        tries++;
        cout << "Guess a number between 1 to 100 : ";
        cin >> guess;

        if (guess == n)
        {
            break;
        }
        else if (guess > n)
        {
            cout << "\nGUESS LOWER\n";
        }
        else
        {
            cout << "\nGUESS HIGHER\n";
        }
    }

    cout << "Congrats! You have guessed the number correctly!" << endl;
    cout << "It took you " << tries << " attempts to guess the number correctly" << endl;
}

/*
This function runs the modification 2 as stated in problem statement!
*/
void modification_2()
{
    float lower = 1;
    float higher = 100;
    int guess = rand() % 100 + 1;
    int option = 0;
    bool correct_guess = false;
    int guess_count = 0;
    int range = 0;
    cout << "Please select a number between 1 to 100 and do not disclose it." << endl;
    cout << "I will guess a number, please tell me the result by enter the corresponding number against the result!" << endl;
    while (!correct_guess)
    {
        cout << "The guessed number is : " << guess << endl
             << endl;
        cout << "Your options are : " << endl;
        cout << "1. Guess LOWER" << endl;
        cout << "2. CORRECT guess" << endl;
        cout << "3. Guess HIGHER" << endl;
        cout << endl
             << "Enter the suitable option from the above menu : ";
        cin >> option;
        guess_count++;
        switch (option)
        {
        case 1:
            higher = guess;
            range = higher - lower + 1;
            guess = ((rand() % range) / 2) + lower;
            break;

        case 2:
            correct_guess = true;
            break;

        case 3:
            lower = guess;
            range = higher - lower + 1;
            guess = ((rand() % range) / 2) + lower;
            break;

        default:
            break;
        }
    }

    cout << endl;
    cout << "Number of guesses it took to find correct number : " << guess_count;
    cout << endl;
}

/*
This function runs the modification 3 as stated in problem statement!
*/
void modification_3()
{
    int lower = 1;
    int higher = 100;
    int guess = 50;
    int option = 0;
    bool correct_guess = false;
    int guess_count = 0;
    cout << "Please select a number between 1 to 100 and do not disclose it." << endl;
    cout << "I will guess a number, please tell me the result by enter the corresponding number against the result!" << endl;
    while (!correct_guess)
    {
        cout << "The guessed number is : " << guess << endl
             << endl;
        cout << "Your options are : " << endl;
        cout << "1. Guess LOWER" << endl;
        cout << "2. CORRECT guess" << endl;
        cout << "3. Guess HIGHER" << endl;
        cout << endl
             << "Enter the suitable option from the above menu : ";
        cin >> option;
        guess_count++;
        switch (option)
        {
        case 1:
            higher = guess;
            guess = (higher + lower) / 2;
            break;

        case 2:
            correct_guess = true;
            break;

        case 3:
            lower = guess;
            guess = (higher + lower) / 2;
            break;

        default:
            break;
        }
    }

    cout << endl;
    cout << "Number of guesses it took to find correct number : " << guess_count;
    cout << endl;
}

/*
This is the main function, which is invoked by the compiler!
*/
int main()
{

    srand((unsigned)time(NULL));
    // Modification 1
    cout << "####################################################" << endl;
    cout << "Basic Program and Modification 1" << endl;
    cout << "####################################################" << endl;
    modification_1();

    // Modification 2
    cout << "####################################################" << endl;
    cout << "Modification 2" << endl;
    cout << "####################################################" << endl;
    modification_2();

    // Modification 3
    cout << "####################################################" << endl;
    cout << "Modification 3" << endl;
    cout << "####################################################" << endl;
    modification_3();
}