#ifndef BSTPAC
#define BSTPAC

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

	void DisplayPostorder(NODE* p)
	{
		if(p != NULL)
		{
			DisplayPostorder(p->left);
			DisplayPostorder(p->right);
			cout << p->info << '\t';
		}
	}
	void DisplayPostorder()
	{
		DisplayPostorder(root);
	}

	void DisplayPreorder(NODE* p)
	{
		if(p != NULL)
		{
			cout << p->info << '\t';
			DisplayPreorder(p->left);
			DisplayPreorder(p->right);
		}
	}
	void DisplayPreorder()
	{
		DisplayPreorder(root);
	}

	void DisplayLeaves(NODE* p)
	{
		if(p != NULL)
		{
			if(p->left == NULL && p->right == NULL)
			{
				cout << p->info << '\t';
			}
			DisplayLeaves(p->left);
			DisplayLeaves(p->right);
		}
	}
	void DisplayLeaves()
	{
		DisplayLeaves(root);
	}

	void DisplayParentsWithTwoChildren(NODE* p)
	{
		if(p != NULL)
		{
			if(p->left != NULL && p->right != NULL)
			{
				cout << p->info << '\t';
			}
			DisplayParentsWithTwoChildren(p->left);
			DisplayParentsWithTwoChildren(p->right);
		}
	}
	void DisplayParentsWithTwoChildren()
	{
		DisplayParentsWithTwoChildren(root);
	}
};


#endif