//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 10 Part 1
//				Due Date		November 6, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program uses a hash table to store pointers to nodes. Each 
// node contains a string month name and the amount of days in that month. 
// The nodes are used in a linked list for every index. The program inserts 
// each month and its days into the hash table and then displays the
// information by traversing an index and then traversing the linked list at 
// that index before proceeding to the next index to do the same thing. 
// Finally the program asks the user for a month's name as input. The program 
// then looks up the month in the hash table and displays the amount of days 
// in that month to the user.
//----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


struct NODE
{
	string month;
	int days;
	NODE* next;
}* list;

int main()
{
	string c, input, months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	int index, days[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	NODE * hash[4] = {};

	//read months into the hash table based on the
	//numerical value of the first three characters
	//to identify the index it will be placed into
	for(int i=0; i<12; i++)
	{
		c = months[i];
		index = (tolower(c[0]) + tolower(c[1]) + tolower(c[2])) % 4;
		NODE * r;
		r = new NODE;
		r->month = c;
		r->days = days[i];

		if(hash[index] == NULL)
		{
			r->next = NULL;
			hash[index] = r;
		}
		else
		{
			r->next = hash[index];
			hash[index] = r;
		}
	}

	//display months
	for(int i=0; i<4; i++)
	{
		list = hash[i];
		while(list != NULL)
		{
			cout << list->month << " | " << list->days << '\t';
			list = list->next;
		}
		cout << endl;
	}

	cout << endl;

	cout << "Enter a month: ";
	cin >> input;
	


	//the sum of the first three characters ascii value in order from Jan - Dec
	//313, 301, 320, 323, 327, 333, 331, 317, 328, 326, 339, 300
	int sum=0;
	string input_short;
	for(int i=0; i < 3 ; i++)
	{
		sum += int(tolower(input[i]));
	}

	index = sum % 4;
	
	for(int i=0; i<3; i++)
	{
		if(i==0)
		{
			input_short += toupper(input[i]);
		}
		else
		{
			input_short += tolower(input[i]);
		}
	}
	cout << endl;

	list = hash[index];
	while(list->month != input_short && list != NULL)
	{
		list = list->next;
	}
	cout << "There are " << list->days << " days in " << input << "!" << endl;
	system("pause");
	return 0;
}

/*
Dec | 31        Sep | 30        Mar | 31
Aug | 31        Jun | 30        Feb | 29        Jan | 31
Oct | 31
Nov | 30        Jul | 31        May | 31        Apr | 30

Enter a month: October

There are 31 days in October!
Press any key to continue . . .
*/