//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 5 Part 2
//				Due Date		October 9, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program uses a linked list that behaves like a queue. 
//          A given integer array is used as input into the queue linked
//          list. This allows the functionality of a linked list but has
//          first in first out*queue) capabilities that a standard linked 
//          list does not. The content of all nodes is then displayed. The 
//          max and min are also calculated and displayed.
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

struct NODE
{
	int info;
	NODE * next;
};

int main()
{
	NODE *first, *last, *placeholder; 
	int b[4] = {3, 9, 8, 1};
	int max, min;

	first = new NODE; 
	first -> info = b[0];
	max = b[0];	min = b[0]; //set max and min to first input
	first -> next = NULL; 
	last = first;
	for(int i = 1; i < 4; i++)
	{
		placeholder = new NODE;
		placeholder -> info = b[i];
		placeholder -> next = NULL;
		last -> next = placeholder;
		last = placeholder;

		//check and update max and min values
		if(b[i] > max) { max = b[i]; }
		if(b[i] < min) { min = b[i]; }
	}

	placeholder = first; //make copy of master
	while(placeholder!=NULL)
	{
		cout << placeholder -> info << " ";
		placeholder = placeholder -> next;
	}
	cout << endl;
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;

	system("pause");
	return 0;
}
/*
3 9 8 1
Max: 9
Min: 1
Press any key to continue . . .
*/