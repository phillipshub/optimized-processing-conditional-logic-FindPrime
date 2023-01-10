/*
Program:FindPrime
Author:Phillip McCullough
Date:1/10/2022
C/Cpp:11+ ANSI Standard

This program is a basic example of optimized conditional logic. Using the
task of determining if a number is prime I express the meaning and value of
optimized conditional logic processing.
-------10--------20--------30--------40--------50--------60--------70--------80
*/
#include <iostream>
#include<cctype>
#include <string>
using namespace std;

bool findPrime(int check_number);

int main()
{
	string check_another, is_prime;
	int number;

	cout << "Welcome to Find Prime.\n";
	
	do
	{
		cout << "\nType a number you would like to check and press [enter/return]: ";
		cin >> number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "\nYou may only enter a number.\n"
				"Type the number you would like to check and press [enter/return]: ";
			cin >> number;
		}
		cin.ignore(INT_MAX, '\n');

		is_prime = findPrime(number) ? " is a prime " : " is not a prime ";

		cout << '\n' << number << is_prime << "number.\n\n"
			"Would you like to check another number? [Yes/No]: ";
		getline(cin, check_another);
		check_another = toupper(check_another[0]);

	} while (check_another != "N");

	return 0;
}

// ----------------------------------------------------------------------------

bool findPrime(int check_number)
{
	int range_max = check_number / 2;

	/*
	Crash course for the curious before taking a closer look at process logic.
	Conditional expressions must evaluate as true for logical statements to be
	executed within a program.
	*/

	// The line below is the one we want to examine most.
	if (check_number % 2 == 0 && check_number != 2 || check_number <= 1) 
		return false;
	/*
	Let's start with the first set of conditions.
	(check_number % 2 == 0 && check_number != 2) This translates to, does
	check_number divided by two have a remainder and is check_number not equal
	to two.

	The purposefully placed (check_number % 2 == 0) is the first condition checked
	in the logical and (&&) statement. This eliminates all even numbers as possibly
	being a prime number. However, the first even number two is a prime number.
	(check_number != 2) The right value condition excludes the number two with the
	not equal logical comparison operator (!=) so that the number two is not falsely
	eliminated from being a prime number.

	Because the number one is unable to be divided and remain an integer the number
	one is controversially excluded from prime numbers. Rather than creating a
	separate statement using operator precedence with the logical or (||) operator
	only in the case of odd numbers check_number will be compared via the comparison
	operator (<=) to exclude one and negitive numbers as prime.

	In conclusion on one line within an orchestrated logical expression all even
	numbers have been eliminated except for the number two. Also, using operator
	precedence as the left value of logical or (||) evaluates to true on even
	numbers the right value is not examined saving many operations by using
	(optimized order processing conditional logic).
	

	With even numbers eliminated the following loop starts testing numbers
	as possibly prime starting with the first non-prime odd number, nine.
	*/
	for (int i = 3; i < range_max; i++)
		if (check_number % i == 0)
			return false;
     // True is returned as check_number is declared to be a prime number.
	return true;
}
