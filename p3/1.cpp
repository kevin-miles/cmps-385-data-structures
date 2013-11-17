//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 3 Part 1
//				Due Date		September 18, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: Using a pre-defined STACK library this program make use of a stack 
//          to convert a user provided input of a positive integer to base 2,
//          base 8, and base 16.
//----------------------------------------------------------------------

#include "STACK.h" //include our own stack library
#include <iomanip>
#include <iostream>

using namespace std;

void convert_base_and_print(int number);

int main()
{
	int input;

	cout << "Enter a POSITIVE INTEGER: ";
	cin >> input;

	convert_base_and_print(input);
	
	system("pause");
	return 0;
}


/*
	Name: convert_base_and_print

	Purpose: receives a positive integer and converts it to base 2, base 8, and base 16. 
	It prints out each converted number.
*/
void convert_base_and_print(int number)
{
	STACK<int, 32> Container;
	int n;
	n = number;

	Container.createStack();
	
	//convert to base 2
	cout << "Base 2: ";
	
	while(!n==0)
	{
	Container.pushStack(n % 2);
	n = n / 2;
	}

	while(!Container.emptyStack())
	{
	n = Container.popStack();
	cout << n;
	}
	cout <<  endl;
	

	//convert to base 8
	n = number;
	cout << "Base 8: ";
	while(!n==0)
	{
		Container.pushStack(n % 8);
		n = n / 8;
	}
	while(!Container.emptyStack())
	{
		n = Container.popStack();
		cout << n;
	}
	cout <<  endl;

	//convert to base 16
	n = number;
	char letter;
	cout << "Base 16: ";
	while(!n==0)
	{
		Container.pushStack(n % 16);
		n = n / 16;
	}
	while(!Container.emptyStack())
	{
	n = Container.popStack();
	if(n >= 10)
	{
	   // convert integers larger than 10 to their letter representations
	   switch(n)
	   {
	   case 10: letter = 'A'; break;
	   case 11: letter = 'B'; break;
	   case 12: letter = 'C'; break;
	   case 13: letter = 'D'; break;
	   case 14: letter = 'E'; break;
	   case 15: letter = 'F'; break;
	   default: letter = ' '; 	   
	   }
	   cout << letter;
	  
	}
	else
	{
	   cout << n;
	}
	
	}
	cout <<  endl;
}

/*
Enter a POSITIVE INTEGER: 163
Base 2: 10100011
Base 8: 243
Base 16: A3
Press any key to continue . . .
*/