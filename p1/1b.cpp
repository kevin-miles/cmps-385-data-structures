//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 1 Part 1b
//				Due Date		September 4, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program generates and stores 15 random integers between 20 and 40.
//          It then identifies the even and odd integers in the array and prints
//          out them to screen formatted in their respective groups.
//----------------------------------------------------------------------	

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/*
	 Name: iseven
	 Purpose: Checks if an integer is even. Returns true or false.
*/
bool iseven(int n)
{
	//checks if divisible by two. if there is a remainder, it is odd
	//and the program returns false
	if(n%2==0)
	{ 
		return true; 
	}
	else
	{ 
		return false;
	}
}

/*
	 Name: printOutput
	 Purpose: Takes two integer vectors as input, prints the formatted contents to screen as output.'
	          Vectors are used instead of arrays to eliminate the need to declare the size. This allows
			  a variable amount of total even or odd numbers every time the program is run.
*/
void printOutput(vector<int> e, vector<int> o)
{
	cout << left << setw(22) << "\tEVEN integers in array: ";
	for(int i=0; i<e.size(); i++)
	{
		cout << e[i] << " ";
	}
	cout << endl;
		cout << left << setw(22) << "\tODD integers in array: ";
	for(int i=0; i<o.size(); i++)
	{
		cout << o[i] << " ";
	}
	cout << endl;
}

/*
	 Name: generateRandomValues
	 Purpose: Per project requirements, this function assumed array pased to it is size 15.
	          Random numbers between 20 and 40 are assigned to each index.
*/
void generateRandomValues(int rand_arr[])
{
	for(int i=0; i<15; i++)
	{
		//generates and assigns random numbers between 20 and 40
		//to the rand_arr index
		rand_arr[i] = rand() % 40 + 20;     
	}
}

/*
	 Name: findEvenOddValues
	 Purpose: Iterates through the integer array of random numbers.
	          If an even number is found the array's value is added to 
			  the even vector, otherwise it is odd and added to the odd
			  vector.
*/
void findEvenOddValues(int rand_num[], vector<int>& e, vector<int>& o)
{
	//loop assumes rand_num is of size 15
	for(int i=0; i<15;i++)
	{
		if(iseven(rand_num[i]))
		{
			e.push_back(rand_num[i]);
		}
		else
		{
			o.push_back(rand_num[i]);
		}
	}
}

int main()
{
	//vectors used to store even and odd values from the random_numbers array
	//for easy output in the printOutput function
	vector<int> even, odd;
	int random_numbers[15]={};

	generateRandomValues(random_numbers); //function assumes size is 15
	findEvenOddValues(random_numbers, even, odd);
	printOutput(even, odd);

	system("pause");
	return 0;
}

/*
		EVEN integers in array: 34 40 24 58 58 22 44
		ODD integers in array: 21 47 29 45 45 21 47 21
Press any key to continue . . .

*/