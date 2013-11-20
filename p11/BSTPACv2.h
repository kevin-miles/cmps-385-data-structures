#ifndef BSTPAC2
#define BSTPAC2

//its not suggested to pollute the namespace so instead of using namespace std
//some suggest to use std::string to use strings in classes
using std::string;

template<class T>
class BST
{
private:
	struct NODE
	{
		T info;
		string name;
		int balance;
		NODE* left, *right;
	};
	NODE* root;
public:
	//constructor
	BST()
	{
		root = NULL;
	}

	void DisplayBalance(T id)
	{
		NODE *p;
		p = Locate(id);
		if (p != NULL)
		{
			cout << '\t' << p->name << ", you have $" << p->balance << " in your account." << endl;
		}
		else
		{
			cout << '\t' << "Could not locate account." << endl;
		}
	}

	void DepositFunds(T id, int amount)
	{
		NODE *p;
		p = Locate(id);
		if (p != NULL)
		{
			p->balance += amount;
			cout << '\t' << p->name << ", you have added $" << amount << " to your account. Your new balance is: $" << p->balance << endl;
		}
		else
		{
			cout << '\t' << "Could not locate account." << endl;
		}
	}

	void WithdrawFunds(T x, int funds)
	{
		NODE *p;
		p = Locate(x);
		if (p != NULL)
		{
			if (funds > p->balance)
			{
				cout << '\t' << "Sorry, you do not have enough money in your account to withdraw the given amount!" << endl;
			}
			else
			{
				p->balance -= funds;
				cout << '\t' << "Success! After withdrawing $" << funds << " your new balance is: $" << p->balance << endl;
			}
		}
	}


	NODE* Locate(T id)
	{
		return Locate(root, id);
	}

	NODE* Locate(NODE * &n, T id)
	{
		//we locate the node by cutting the number of choices in half each time
		if (id < n->info)
		{
			Locate(n->left, id);
		}
		else if (id > n->info)
		{
			Locate(n->right, id);
		}
		else
		{
			//here we have located the correct node
			return n;
		}
	}
	void Insert(NODE* &p, T x, string name, int balance)
	{
		NODE *q;
		if (p == NULL)
		{
			q = new NODE;
			q->info = x;
			q->name = name;
			q->balance = balance;
			q->left = NULL;
			q->right = NULL;
			p = q;
		}
		else if (p->info > x)
		{
			Insert(p->left, x, name, balance);
		}
		else
		{
			Insert(p->right, x, name, balance);
		}
	}

	void Insert(T x, string name, int balance)
	{
		Insert(root, x, name, balance);
	}

	void DisplayInorder(NODE* p)
	{
		if (p != NULL)
		{
			DisplayInorder(p->left);
			cout << p->name << '\t' << p->info << '\t' << p->balance << '\t' <<endl;
			DisplayInorder(p->right);
		}
	}
	void DisplayInorder()
	{
		DisplayInorder(root);
	}

	void Delete(NODE * &n, T id)
	{
		//we locate the node by cutting the number of choices in half each time
		if (id < n->info)
		{
			Delete(n->left, id);
		}
		else if (id > n->info)
		{
			Delete(n->right, id);
		}
		else
		{
			//here we have located the correct node
			DeleteNode(n);
		}		
	}
	void Delete(T id)
	{
		Delete(root, id);
	}

	void DeleteNode(NODE * &n)
	{

		/*
		//three conditions for deleting
		1.) No Children
		2.) One Child
		3.) Three Children

		Case 1:
		Delete the node.
		Case 2:
		Remove node.
		Replace with it's child.
		Case 3:
		Find predecessor or successor. (Will always have 0 or one children)
		Replace with predecessor or successor.
		Delete it.
		*/
		NODE * p;
		p = n;
		if (n->left == NULL) //left is null
		{
			n = n->right;
			delete p;
		}
		else if (n->right == NULL) //left is not null, but right is
		{
			n = n->left;
			delete p;
		}
		else //left and right children exist
		{
			p = n->left;
			while (p->right != NULL) //locate predecessor of root
			{
				p = p->right;
			}
			n->info = p->info; //swap contents
			n->name = p->name; 
			n->balance = p->balance; 
			Delete(n->left, p->info); //this deletes the original predecessor
		}
	}



};


#endif