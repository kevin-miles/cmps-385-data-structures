//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 10 Part 2
//				Due Date		November 6, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program creates a binary search tree out of given integer data.
//          Recursive functions were written to traverse all nodes and display 
//          their info in preorder, postorder, and inorder. Additionally, a 
//          recursive function to display only the leaves of the tree and only 
//          parents with two children was added. 
//----------------------------------------------------------------------

#include <iostream>
#include <string>
#include "BSTPAC.h"

using namespace std;


int main()
{
	BST<int> t;
	
	int a[6] = {25,9,36,2,17,40};

	for(int i=0; i < 6; i++)
	{
		t.Insert(a[i]);
	}
	cout << "Inorder: ";
	t.DisplayInorder();
	cout << endl;
	cout << "Postorder: ";
	t.DisplayPostorder();
	cout << endl;
	cout << "Preorder: ";
	t.DisplayPreorder();
	cout << endl;
	cout << "Leaves: ";
	t.DisplayLeaves();
	cout << endl;
	cout << "Parents with TWO Children: ";
	t.DisplayParentsWithTwoChildren();
	cout << endl;

	system("pause");
	return 0;
}
/*
Inorder: 2      9       17      25      36      40
Postorder: 2    17      9       40      36      25
Preorder: 25    9       2       17      36      40
Leaves: 2       17      40
Parents with TWO Children: 25   9
Press any key to continue . . .
*/