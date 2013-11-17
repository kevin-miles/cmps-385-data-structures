#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
template<class T>
class BST
{
private: 
	struct NODE
	{
		T info;
		NODE* left, * right;
	};
	NODE* root;
public:
	//constructor
	BST()
	{
		root = NULL;
	}

	void Insert(NODE* &p, T x)
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
	
	void Insert(T x)
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

	system("pause");
	return 0;
}