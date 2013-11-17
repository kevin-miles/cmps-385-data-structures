#include <iostream>
#include <iomanip>

using namespace std;

class BST
{
private: 
	struct NODE
	{
		int info;
		NODE* left, * right;
	};
	NODE* root;
public:
	//constructor
	BST()
	{
		root = NULL;
	}

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
	
	void Insert(int x)
	{
		Insert(root, x);
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
	void DisplayInorder()
	{
		DisplayInorder(root);
	}
};

int main()
{
	BST t;
	
	int a[8] = {30,10,16,35,40,5,33,11};

	for(int i=0; i < 8; i++)
	{
		t.Insert(a[i]);
	}

	t.DisplayInorder();
	cout << endl;
	system("pause");
	return 0;
}