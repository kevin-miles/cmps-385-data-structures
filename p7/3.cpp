//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 7 Part 3
//				Due Date		October 23, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program uses custom ordered list and queue libraries to load 
//          data from a text file into a queue. The queue is printed. The queue
//          is then popped into an ordered list and sorted from oldest to youngest
//          by age. Then both the queue and ordered list are printed. The queue 
//          will just show NULL because its contents were popped out.
//----------------------------------------------------------------------

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include "QUEUELINK.h" 
#include "OLSPAC_fileIO.h"

using namespace std;

int main()
{
	fstream f;
	string name;
	int age;
	QUEUELINK Q;
	OLSFIO O;

	O.CreateOrdered();
	Q.CreateStack();

	f.open("Data.txt", ios::in);
	//load file contents
	while(!f.eof())
	{
		f >> name >> age;
		Q.Push(name, age);
	}
	f.close();
	cout << "Queue: ";
	Q.Display();
	cout << endl;

	while(!Q.Empty())
	{
		Q.Pop(name, age);

		O.Insert(name, age);
	}
	//this should just show null because we just
	//popped everything out!
	cout << "Queue: ";
	Q.Display();
	cout << endl;

	cout << "Ordered List: ";
	O.Display();
	cout << endl;

	system("pause");
	return 0;
}			

/*
Queue: Smith,John  25 --> Jackson,Adam  22 --> Jones,Jay  55 --> Miller,Ana  17--> Obama,Barack  34 --> NULL

Queue: NULL

Ordered List: Jones,Jay 55 --> Obama,Barack 34 --> Smith,John 25 --> Jackson,Adam 22 --> Miller,Ana 17 --> NULL

Press any key to continue . . .
*/