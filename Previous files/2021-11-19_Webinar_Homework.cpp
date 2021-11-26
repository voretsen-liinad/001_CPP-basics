// 2021-11-19_Webinar_Homework.cpp 
// homework (tasks 1 - 5) - webinar of November 19, 2021
// Created by Daniil Nesterov (e-mail: maidanov1991@yandex.ru)

#include <iostream>

using namespace std; 


//Task 1.=============================================================================================================================================//
//Write a program checking if a sum of two (inputted) numbers belongs to the segment from 10 to 20 (including), 
//if yes - display a string "true", else - "false"

void vTask1()
{
	cout << "Task 1.====================================================================\n" 
		 << "The program #1 checks if a sum of two inputted numbers\n"
		 << "belongs to the segment from 10 to 20.\n\n"; 
	
	double dNumOne{ 0 }, dNumTwo{ 0 };
	
	cout << "Enter number #1: "; 
	cin >> dNumOne; 
	
	cout << "Enter number #2: ";
	cin >> dNumTwo; 

	string sResult1{ "" }; 
	sResult1 = ((dNumOne + dNumTwo >= 10) && (dNumOne + dNumTwo <= 20)) ? "true" : "false"; 

	cout << "Program #1 result: " << sResult1 << "\n\n\n\n"; 
}
//End of Task 1.=====================================================================================================================================//


//Task 2.=============================================================================================================================================//
//Write a program displaying a string "true" if two integer constants defined at the program's beginning 
//are both equal to 10, or their sum is 10. Else "false".

void vTask2()
{
	cout << "Task 2.====================================================================\n"
		 << "The program #2 checks whether at least one of the next conditions is met: \n"
		 << " - two defined in program #2 integer constants are both equal to 10;\n"
		 << " - the sum of these two integer constants is equal to 10.\n\n"; 

	const int CONSTANT_1{ 11 }, CONSTANT_2{ -1 }; //the two integer constants are defined here

	cout << "The two defined integer constants: CONSTANT_1 = " << CONSTANT_1 << ", CONSTANT_2 = " << CONSTANT_2 << "\n\n"; 

	cout << "Program #2 result: "; 

	if ((CONSTANT_1 == 10 && CONSTANT_2 == 10) || (CONSTANT_1 + CONSTANT_2 == 10))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}

	cout << "\n\n\n\n"; 
}
//End of Task 2.=====================================================================================================================================//


//Task 3.=============================================================================================================================================//
//Write a program displaying a list of all odd numbers from 1 to 50. 
//For example: "Your numbers: 1 3 5 7 9 11 13 …". Use any C++ cycle to solve the task. 

void vTask3()
{
	cout << "Task 3.====================================================================\n"
		 << "The program #3 displays all odd numbers from 1 to 50.\n\n";

	cout << "Program #3 result:";

	unsigned short int i{ 1 }; 

	do 
	{
		cout << " " << i; 
		i += 2; 
	} while (i < 50);

	cout << "\n\n\n\n";
}
//End of Task 3.=====================================================================================================================================//


//Task 4.=============================================================================================================================================//
//*. Write a program checking if some number is a prime. 
//A prime number is a positive integer number that is divisible only by one and by itself. 

void vTask4()
{
	cout << "Task 4.====================================================================\n"
		 << "The program #4 checks if an inputted integer number is prime.\n\n";

	int iNumber{ 0 };
	
	cout << "Enter an integer number: "; 
	cin >> iNumber; 

	cout << "Program #4 result: " << iNumber;
	
	if (iNumber < 2) cout << " is not prime"; //verification of compliance with the minimum required value
	else
	{
		if (iNumber == 2) cout << " is prime"; //checking if the inputted number is the first prime
		else
		{
			bool bIsPrime{ true };

			if (iNumber % 2 == 0)	//parity check
			{
				cout << " is not prime"; 
				bIsPrime = false; 
			}
			else
			{
				for (int i{ 3 }; i < iNumber; i += 2)	//divisibility test by odd divisors
				{
					if (iNumber % i == 0)
					{
						cout << " is not prime";
						bIsPrime = false;
						break;
					}
				}
			}

			if (bIsPrime == true) cout << " is prime"; 
		}	
	}

	cout << "\n\n\n\n";
}
//End of Task 4.=====================================================================================================================================//


//Task 5.=============================================================================================================================================//
//*. A user inputs a number (year): from 1 to 3000. 
// Write a program that defines if the inputted year is leap. 
// Each fourth year is leap, except every hundredth year, but every four hundredth year is leap. 
// Output the program's results to the console. 

void vTask5()
{
	cout << "Task 5.====================================================================\n"
		 << "The program #5 checks whether an inputted year is leap.\n\n";
	
	unsigned short int nYear{ 0 }; 

	cout << "Enter a year (from 1 to 3000): ";
	cin >> nYear; 

	cout << "Program #5 result: " << nYear; 
	
	if (nYear < 1 || nYear > 3000) cout << " year does not belong to the segment from 1 to 3000."; 
	else
	{
		if (nYear % 400 == 0) cout << " year is leap"; 
		else
		{
			if (nYear % 100 == 0 ) cout << " year is not leap"; 
			else
			{
				if (nYear % 4 == 0) cout << " year is leap"; 
				else cout << " year is not leap"; 
			}
		}
	}
	
	cout << "\n\n\n\n";
}
//End of Task 5.=====================================================================================================================================//


int main()
{
	vTask1(); //Task 1

	vTask2(); //Task 2

	vTask3(); //Task 3

	vTask4(); //Task 4

	vTask5(); //Task 5

	return 0;
};

