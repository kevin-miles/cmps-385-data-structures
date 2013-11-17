#include <iostream>
#include <iomanip>

using namespace std;

struct NODE
{
	int info;
	NODE * next;
};

void Display(NODE * p)
{
	NODE * t = p;
	while(t != NULL)
	{
		cout << t->info << " -> ";
		t = t->next;
	}
	cout << "NULL" << endl;
}
void Insert(NODE * & p, int x)
{
	//insert x in an ordered linked list pointed by p
	NODE *t, *q, *r;
	r = new NODE;
	r->info = x;
	t = q = p;

	if(p == NULL) //list is empty
	{
		p=r;
		r->next = NULL;
	}
	else
	{
		//find insertion place
		//looks until it reaches null or the info of t  is larger OR equal than r
		while(t != NULL && r->info >  t->info) 
		{
			q = t;
			t = t->next;
		}

		//t didnt move because no conditions were met
		//t is equal to or larger than r
		//so r must go before it and the master list must be updated
		if(t == p)
		{
			r->next = t;
			p = r;
		}
		else
		{
			//places  r in between two locations
			r->next = t;
			q->next = r;
		}
	}
}

int main()
{
	NODE* p;
	p = NULL;
	Insert(p, 20);
	Insert(p, 10);
	Insert(p, 40);
	Insert(p, 5);
	
	Display(p);
	system("pause");
	return 0;
}			