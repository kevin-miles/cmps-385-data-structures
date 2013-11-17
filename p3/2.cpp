//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 3 Part 2
//				Due Date		September 18, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program generates 10 random integers < 100 and loads them into a stack.
//          All the generated numbers are printed. Even numbers are copied to an EVEN
//          stack and odd numbers into an ODD stack. All even and odd numbers are printed.
//----------------------------------------------------------------------

#include "STACK.h" //include our own stack library
#include <iomanip>
#include <iostream>
#include <time.h>

using namespace std;

void generate_random_sort_stacks();

int main()
{
	generate_random_sort_stacks();
	system("pause");
	return 0;
}

void generate_random_sort_stacks()
{
	STACK<int, 10> Temp, Even, Odd;
	int n;

	//initialize stacks
	Temp.createStack();
	Even.createStack();
	Odd.createStack();

	srand(time(0));
	//store 10 random integers < 100 in the Temp stack
	for(int i=0; i < 10; i++)
	{
		n = rand() % 99 + 1; //1-99 (project requirement is < 100)
		Temp.pushStack(n);
	}    
	
	//print stack contents and separate stack contents 
	//by pushing odd numbers into Odd stack and even numbers
	//into Even stack
	cout << "All Numbers: ";

	while(!Temp.emptyStack())
	{
		n = Temp.popStack();
		cout << n << " ";
		if(n % 2==0)
		{
			Even.pushStack(n);
		}
		else
		{
			Odd.pushStack(n);
		}
	}
	cout <<  endl;

	//print out even numbers from their stack
	cout << "EVEN numbers: ";
	Temp.createStack(); //clear stack
	//load Even stack back into Temp to reverse the order
	while(!Even.emptyStack())
	{
		n = Even.popStack();
		Temp.pushStack(n);
	}
	//print out contents of stack
	while(!Temp.emptyStack())
	{
		n = Temp.popStack();
		cout << n << " ";
	}
	cout << endl;

	//print out odd numbers from their stack
	cout << "ODD numbers: ";
	Temp.createStack(); //clear stack
	//load Odd stack back into Temp to reverse the order
	while(!Odd.emptyStack())
	{
		n = Odd.popStack();
		Temp.pushStack(n);
	}
	//print out contents of stack
	while(!Temp.emptyStack())
	{
		n = Temp.popStack();
		cout << n << " ";
	}
	cout << endl;
}


/*
All Numbers: 99 26 47 35 81 95 6 43 48 32
EVEN numbers: 26 6 48 32
ODD numbers: 99 47 35 81 95 43
Press any key to continue . . .
*/