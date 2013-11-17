//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 5 Part 1
//				Due Date		October 9, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program uses a linked list that acts like a stack, giving
//          it a first in last out behavior. The contents of the nodes are
//          given input from a provided integer array. The contents of the 
//          nodes are printed. The total of all the nodes is calculated and 
//          printed. The amount of nodes is calculated and printed.
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;
struct NODE
{
	int info;
	NODE *next; //the address of the next node
} *Link, *Last ;

int main()
{
	Last = NULL;

	int d[5] = {3,9,8,5,7},
		sum = 0,
		operand = 0,
		counter = 0;

	//create linked list with contents of d array
	for(int i=0; i<5; i++)
	{
		Link = new NODE;
		Link->info = d[i];
		Link->next = Last;
		Last = Link;
	}

	Link = Last;

	//display content of all nodes
	cout << "Content of Nodes: ";
	while(Link != NULL)
	{
		operand = Link->info;
		cout << operand << " "; //print current number
		sum += operand; //add to sum
		counter++; //increment node counter
		Link = Link->next; //move to next location
	}
	cout << endl;
	cout << "Total Nodes: " << counter << endl;
	cout << "Sum of all Nodes: " << sum << endl;

	system("Pause");
	return 0;
}
/*
Content of Nodes: 7 5 8 9 3
Total Nodes: 5
Sum of all Nodes: 32
Press any key to continue . . .
*/