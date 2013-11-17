#include <iostream>
#include <iomanip>

using namespace std;

struct NODE
{
	int info;
	NODE* left, * right;
};

void Insert(NODE* &p, int x)
{
	NODE *q;
	if(p == NULL)
	{
		q = new NODE;
		q->info = x;
		q->left = NULL;
		q->right = NULL;
		p = q;
	}
	else if(p->info > x)
	{
		Insert(p->left, x);
	}
	else
	{
		Insert(p->right, x);
	}
}

void DisplayInorder(NODE* p)
{
	if(p != NULL)
	{
		DisplayInorder(p->left);
		cout << p->info << '\t';
		DisplayInorder(p->right);
	}
}

int main()
{
	int a[8] = {30,10,16,35,40,5,33,11};
	NODE* root;
	root = NULL;
	for(int i=0; i<8;i++)
	{
		Insert(root, a[i]);
	}

	//display all nodes using inorder traversa;
	DisplayInorder(root);


	system("pause");
	return 0;
}