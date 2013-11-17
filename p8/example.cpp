#include <iostream>
#include <string>
#include "BSTPAC.h"

using namespace std;


int main()
{
	BST<int> t;
	
	int a[8] = {30,10,16,35,40,5,33,11};

	for(int i=0; i < 8; i++)
	{
		t.Insert(a[i]);
	}
	t.DisplayInorder();
	cout << endl;

	BST<string> q;
	string days[7] = {"Mon", "Tue", "Wed", "Thr", "Fri", "Sat", "Sun"};


	for(int i=0; i < 7; i++)
	{
		q.Insert(days[i]);
	}

	q.DisplayInorder();
	cout << endl;

	BST<char> r;
	for(char i='A'; i <='K'; i++)
	{
		r.Insert(i);
	}
	r.DisplayInorder();
	cout << endl;
	system("pause");
	return 0;
}