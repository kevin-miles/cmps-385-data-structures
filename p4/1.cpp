//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 4 Part 1
//				Due Date		September 25, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program evaluates a postfix expression given by user input.
//          It replaces alpha values a with 3, b with 11, c with 5, and d with 8.
//          The program stores these values into a stack and when an operator is
//          found(+,-,*) the previous two values from the stack are evaluated with 
//          the operator given and the result is pushed back into the stack. This is 
//          repeated until all values are calculated and only the answer remains.
//          The answer is printed to screen. The program is continued in a loop until
//          the user opts-out.
//----------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include "STACK.h"
#include <string>

using namespace std;

void eval_postfix(string input);
bool loop(string question);

int main()
{
	string input;
	bool again;

	while(true)
	{
		cout << "Enter a postfix expression: ";
		getline(cin, input, '\n'); //third input is delimiting sequence to prevent having to use cin.ignore to clear buffer
		eval_postfix(input);

		again = loop("CONTINUE(y/n)?");
		if(!again) { break; }
	}

	system("pause");
	return 0;
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
		cout << question << " ";
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
Name:     eval_postfix
Purpose:  evaluate a string and calculate the value based on the postfix expression that was given
		  in this case a=3, b=11, c=5, and d=8 per project requirements
*/
void eval_postfix(string input)
{
	STACK<int, 128> S;
	S.createStack();
	int val1, val2, val_result;
	for(int i=0; i<input.length(); i++)
	{
		//evaluate the current character of input
		//if it is an operator it will evaluate the previous two in the Stack
		//otherwise it will push the numeric value into the stack
		switch(tolower(input[i]))
		{
		case 'a': 
			S.pushStack(3);
			break;
		case 'b':
			S.pushStack(11);
			break;
		case 'c':
			S.pushStack(5);
			break;
		case 'd':
			S.pushStack(8);
			break;
		case '*':
			val1 = S.popStack();
			val2 = S.popStack();
			val_result = val1 * val2;
			S.pushStack(val_result);
			break;
		case '+':
			val1 = S.popStack();
			val2 = S.popStack();
			val_result = val1 + val2;
			S.pushStack(val_result);
		break;
		case '-':
			val1 = S.popStack();
			val2 = S.popStack();
			val_result = val2 - val1;
			S.pushStack(val_result);
			break;
		}
	}
	cout << "\tValue: " << S.popStack();

	cout << endl;
}
