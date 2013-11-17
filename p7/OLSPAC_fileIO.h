#ifndef OLSPACFIO
#define OLSPACFIO
using namespace std;
class OLSFIO
{
private:
	struct NODE
	{
		string name;
		int age;
		NODE * next;
	};

	NODE * ordered;
public:
	void CreateOrdered(){ ordered = NULL; }
	
	void Insert(string name, int age)
	{
		//insert x in an ordered linked list pointed by p
		NODE *t, *q, *r;
		r = new NODE;
		r-> name = name;
		r-> age = age;

		if(ordered == NULL) //list is empty
		{
			ordered=r;
			r->next = NULL;
		}
		else
		{
			t=q=ordered;
			//find insertion place
			//looks until it reaches null or the info of t  is larger OR equal than r
			while(t != NULL && r->age <  t->age) 
			{
				q = t;
				t = t->next;
			}

			//t didn't move because no conditions were met
			//t is equal to or larger than r
			//so r must go before it and the master list must be updated
			if(t == ordered)
			{
				r->next = t;
				ordered = r;
			}
			else
			{
				//places  r in between two locations
				//q is less than r and t is more than or equal to r
				r->next = t;
				q->next = r;
			}
		}
	}

	void Display()
	{
		NODE * t = ordered;
		while(t != NULL)
		{
			cout << t->name << " " << t->age << " --> ";
			t = t->next;
		}
		cout << "NULL" << endl;
	}
};

#endif