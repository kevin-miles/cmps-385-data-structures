//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 7 Part 2
//				Due Date		October 23, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: I modified the provided OLSPAC library to reverse the order of 
//          the items when they are inserted. This allows the functions to
//          print out in descending order, with the highest exponent to the
//          left of the equation. A user inputs the coefficients and powers
//          of a function until they exit the loop by giving the input of 
//          0 0. The program then prints out the contents of the ordered link
//          object in the format of a written math function. The user then
//          provides input of the variable value of the function. The program 
//          computes the function with the provided input and prints the answer.
//----------------------------------------------------------------------
#include <iomanip>
#include <iostream>
#include <ctime>
#include "OLSPAC_function.h" 

using namespace std;

int main()
{
	int a, b;
	float avg, x;
	bool again = true;
	OLS_function<int> Order;

	Order.CreateOrdered();
	
	while(again)
	{
		cout << "\tEnter the coefficient and power of a term (0,0 to stop): ";
		cin >> a >> b;

		if(a == 0 && b == 0)
		{
			again = !again; //user wants to exit loop
		}
		else
		{
			Order.Insert(a, b);
		}

	}

	Order.Display();

	cout << "To compute F(x) please enter the \"x\" value: ";
	cin >> x;
	
	cout << "\tF(" << x << ") = ";
	cout << fixed << showpoint << setprecision(2); //formatting
	cout << Order.Compute_Function(x) << endl;

	system("pause");
	return 0;
}			

/*
		Enter the coefficient and power of a term (0,0 to stop): 3 4
		Enter the coefficient and power of a term (0,0 to stop): 7 3
		Enter the coefficient and power of a term (0,0 to stop): 4 2
		Enter the coefficient and power of a term (0,0 to stop): 3 0
		Enter the coefficient and power of a term (0,0 to stop): 0 0
This is your function F(x)
		 F(x) = 3x^4 + 7x^3 + 4x^2 + 3x^0
To compute F(x) please enter the "x" value: -4
		F(-4) = 387.00
Press any key to continue . . .
*/