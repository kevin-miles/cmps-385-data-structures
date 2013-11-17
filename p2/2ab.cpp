//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 2 Part 2
//				Due Date		September 11, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program implements a recursive function based on the
//          given conditions for problem 2. The recursive functions
//          were written in code they are called by the main program.
//          The g() function is timed in seconds using <ctime>.
//----------------------------------------------------------------------	
#include <iostream>
#include <ctime>

using namespace std;

/*
	Name: Sum
	Purpose: Recursive function that takes two input integers.
*/
int sum(int n, int m)
{
	if(n == m)
	{
		return m;
	}
	else
	{
		return n + sum(n + 1, m); //calls self
	}

}

/*
	Name: g
	Purpose: Recursive function that takes a single integer input
*/
int g(int n)
{
	if(n <= 3)
	{
		return 2;
	}
	else
	{
		return n + g(n-1) + g(n-2); //calls self twice
	}
}

int main()
{
	time_t start, finish; //create two time_t objects

	cout << sum(3, 8) << endl;
	time(&start); //assign current time to time_t object start
	cout << g(41) << endl;
	time(&finish); //assign time after execute to time_t object finish

	cout << "Runtime: " << difftime(finish, start) << " seconds" << endl; //used difftime function available from ctime library

	system("pause");
	return 0;
}
/*
33
779585027
Runtime: 5 seconds
Press any key to continue . . .
*/