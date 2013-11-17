//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 2 Part 1
//				Due Date		September 11, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: Initially the program prints the array contents using a template
//          function Display(). This program uses the <algorithm> STL function 
//          sort() to sort all the arrays. The arrays are finally printed again
//          in their sorted order.
//----------------------------------------------------------------------
#include <algorithm>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
	 Name: Display
	 Purpose: Template function. Passed an array(arr[]) and an integer(n) value that is the length
			  of the array. The Function uses a for loop with an upper bounds of n and prints the
			  array contents using cout.
*/
template <class T>
void Display(T arr[], int n)
{
	for(int i=0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int a[5] = {3,8,1,9,2};
	string day[5] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	//original day[] was day[7], I changed it to day[5]
	char c[9] = {'s', 'e', 'p', 't', 'e', 'm', 'b', 'e', 'r'};
	//was c[5] in the homework, but the char array had too many initialized values
	//switched it to c[9]

	cout << left << setw(25) << "Array a before sort: "; 
	Display(a, 5);
	sort(a, a+5); //from <algorithm>
	cout << left << setw(25) << "Array a after sort: ";
	Display(a, 5);

	
	cout << left << setw(25) << "Array day before sort: "; 
	Display(day, 5);
	sort(day, day+5); //from <algorithm>
	cout << left << setw(25) << "Array day after sort:";
	Display(day, 5);

	cout << left << setw(25) << "Array c before sort: "; 
	Display(c, 9);
	sort(c, c+9); //from <algorithm>
	cout << left << setw(25) << "Array c after sort: ";
	Display(c, 9);

	system("pause");
	return 0;
}