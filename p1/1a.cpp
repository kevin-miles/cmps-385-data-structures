//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 1 Part 1a
//				Due Date		September 4, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program uses members of the <cctype> library to calculate
//          the number of uppercase, lowercase, digits, and vowels in the
//          given user input and prints the information to screen.
//----------------------------------------------------------------------	
#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>

using namespace std;

/*
	 Name: isvowel
	 Purpose: Checks if input is an uppercase or lowercase vowel. Returns true or false.
*/
bool isvowel(char c)
{
	//check if character passed is upper or lowercase vowel
	if(c=='A' || c=='a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u')
	{ 
		return true; 
	}
	else
	{ 
		return false;
	}
}

/*
	 Name: printCounters
	 Purpose: Prints the information passed to it.
*/
void printCounters(int u, int l, int d, int v)
{
	cout << setfill('.') << left << setw(30) << "\tNo. of uppercase letters" << right << setw(4) << u << endl;
	cout << setfill('.') << left << setw(30) << "\tNo. of lowercase letters" << right << setw(4) << l << endl;
	cout << setfill('.') << left << setw(30) << "\tNo. of digits" << right << setw(4) << d << endl;
	cout << setfill('.') << left << setw(30) << "\tNo. of vowels" << right << setw(4) << v << endl;
}

/*
	 Name: getCountData
	 Purpose: Gets the user input and calculates the total upper, lower, digit, and vowel amounts.
	          Finally, it calls a function to print the output.
*/
void getCountData()
{
	char curr_char;
	//counters
	int upper = 0, 
		lower = 0, 
		digit = 0, 
		vowel = 0;

	cout << "Enter a sentence: ";

	cin.get(curr_char);

	//if the program makes it to this point then the program assumes the
	//first character was not a new line and it will scan each character until a newline is found
	while(curr_char!='\n')
	{
		if (isupper(curr_char))
		{
			upper++;
		}
		else if (islower(curr_char))
		{
			lower++;
		}
		else if (isdigit(curr_char))
		{
			digit++;
		}

		if (isvowel(curr_char))
		{
			vowel++;
		}

		cin.get(curr_char);
	}

	printCounters(upper, lower, digit, vowel);
}


int main()
{
	getCountData();
	system("pause");
	return 0;
}

/*

Enter a sentence: Fall 2012 Starts
		No. of uppercase letters........2
		No. of lowercase letters........8
		No. of digits...................4
		No. of vowels...................2
Press any key to continue . . .

*/