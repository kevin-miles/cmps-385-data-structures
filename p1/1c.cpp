//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 1 Part 1c
//				Due Date		September 4, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program displays each day in the Days[7][15] array with
//          the length of each day. It replaces "Sat" with "Saturday" then
//          replaces each day with UPPERCASE characters and prints all the days
//          to screen again.
//----------------------------------------------------------------------	

#include <iostream>
#include <iomanip>

using namespace std;

/*
	 Name: printOutput
	 Purpose: Prints each day of the week[][] array with its length.
*/
void printOutput(char week[][15])
{
	for(int i=0; i<7; i++)
	{
		cout <<"\t" << setw(10) << week[i] << " is " << strlen(week[i]) << " characters long." << endl;
	}
	cout << endl << endl; //formatting
}

/*
	 Name: makeUpper
	 Purpose: Makes each day in the week[][] array uppercase.
*/
void makeUpper(char week[][15])
{
	for(int i=0; i<7; i++)
	{
		strupr(week[i]);
	}
}

int main()
{
	char days[7][15] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Sat", "Sunday"};

	printOutput(days);
	strcpy(days[5], "Saturday"); //swap sat with Saturday
	makeUpper(days); //make array all uppercase
	printOutput(days);

	system("pause");
	return 0;
}

/*
			Monday is 6 characters long.
		   Tuesday is 7 characters long.
		 Wednesday is 9 characters long.
		  Thursday is 8 characters long.
			Friday is 6 characters long.
			   Sat is 3 characters long.
			Sunday is 6 characters long.


			MONDAY is 6 characters long.
		   TUESDAY is 7 characters long.
		 WEDNESDAY is 9 characters long.
		  THURSDAY is 8 characters long.
			FRIDAY is 6 characters long.
		  SATURDAY is 8 characters long.
			SUNDAY is 6 characters long.


Press any key to continue . . .
*/

