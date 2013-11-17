//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 4 Part 2
//				Due Date		September 25, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: THis program evaluates user input of a given sentence and 
//          returns if it is a palindrome or not by printing to screen 
//          "Palindrome" or "Not a Palindrome". Stacks are used to evaluate 
//          the string. A Left-to-right and a temporary stack are filled with each
//          character of the string. The temporary is popped and pushed into the
//          right-to-left stack. Each character is then evaluated to see if it matches
//          the other stack. At the end the program checks if the right-to-left stack is empty
//          If not, then it is not a palindrome. If it is then they both matched all chars
//          and it is a Palindrome.
//----------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include "STACK.h"
#include <string>

using namespace std;

void eval_palindrome(string input);
bool loop(string question);

int main()
{
	string input;
	bool again;
	while(true)
	{
		cout << "Enter a sentence: ";
		getline(cin, input, '\n'); //third input is delimiting sequence to prevent having to use cin.ignore to clear buffer
		eval_palindrome(input);

		again = loop("CONTINUE(y/n)?");
		if(!again){ break; }
	}

	system("pause");
	return 0;
}
/*
Name: eval_palindrome
Purpose: Take a string input. Prints "Palindrome" if it is a palindrome, prints "Not a Palindrome" if not.
*/
void eval_palindrome(string input)
{
	STACK<char, 128> LTR, RTL, Temp;

	LTR.createStack();
	RTL.createStack();
	Temp.createStack();

	char l1, l2, temp;

	//loop until the length of the input is met
	//push each character into the LTR and Temp stacks
	//if they are alpha otherwise skip them and continue the loop
	for(int i=0; i<input.length(); i++)
	{
		temp = tolower(input[i]);
		if(isalpha(temp))
		{
			LTR.pushStack(temp);
			Temp.pushStack(temp);
		}
		else
		{
			//skip non alpha characters
			continue;
		}
	}

	//pop the Temp stack and push the result into RTL stack
	//until Temp is empty
	while(!Temp.emptyStack())
	{
		temp = Temp.popStack();
		RTL.pushStack(temp);
	}

	//pop the LTR and RTL stack until LTR is empty.
	//break from loop if the characters do not match
	while(!LTR.emptyStack())
	{
		l1 = LTR.popStack();
		l2 = RTL.popStack();
		if(l1 != l2){ break; }
	}

	//if RTL is not empty then the word is not a palindrome
	//it means we exited from the previous loop prematurely because
	//two characters did not match during the evaluation
	if(RTL.emptyStack())
	{
		cout << endl << "\tPalindrome";
	}
	else
	{
		cout << endl << "\tNot a Palindrome";
	}

}

/*
Name:     loop
Purpose:  takes a string question that is expected to have a YES or NO answer.
		  the function loops until the user enters 'N' or 'n' for NO and a false value is returned. 
		  Otherwise the user can enter 'Y' or 'y' for YES and a true value is returned. 
*/
//question should expect a YES or NO answer
bool loop(string question)
{
	bool again = true;
	char input;
	while(again)
	{
		cout << endl << question << " ";
		cin.get(input);
		cin.ignore(); //ignore trailing \n
		if(input == 'n' || input =='N')
		{
			again = false;
			return false;
		}
		else if( input=='Y' || input=='y')
		{
			again = false;
			return true;
	}
	}
	
}

/*
Enter a sentence: Too bad, I hid a boot

		Palindrome
CONTINUE(y/n)? y
Enter a sentence: Do Geese see God?

		Palindrome
CONTINUE(y/n)? n
Press any key to continue . . .
*/