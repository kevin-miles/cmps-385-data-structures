#ifndef OLSPAC
#define OLSPAC

template <class T>
class OLS
{
private:
	struct NODE
	{
		T info;
		NODE * next;
	};

	NODE * ordered;
public:
	void CreateOrdered(){ ordered = NULL; }
	
	void Insert(T x)
	{
		//insert x in an ordered linked list pointed by p
		NODE *t, *q, *r;
		r = new NODE;
		r->info = x;

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
			while(t != NULL && r->info >  t->info) 
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
			cout << t->info << " -> ";
			t = t->next;
		}
		cout << "NULL" << endl;
	}

	void DisplayOdd()
	{
		NODE * t = ordered;
		cout << "ODD: ";
		while(t != NULL)
		{
			if(t->info % 2 != 0)
			{
				cout << t->info << " -> ";
			}
			t = t->next;
		}
		cout << "NULL" << endl;
	}

	void DisplayEven()
	{
		NODE * t = ordered;
		cout << "EVEN: ";
		while(t != NULL)
		{
			if(t->info % 2 == 0)
			{
				cout << t->info << " -> ";
			}
			t = t->next;
		}
		cout << "NULL" << endl;
	}

	void DisplayMaxMin()
	{
		NODE * t = ordered;
		int max, min;
		if(t != NULL)
		{
			max = t->info;
			min = t->info;
			t = t->next;
		}

		while(t != NULL)
		{
			if(t->info > max) max = t->info;
			if(t->info < min) min = t->info;
			t = t->next;
		}

		cout << "MAX: " << max << endl;
		cout << "MIN: " << min << endl;
	}

	float ComputeAve()
	{
		NODE * t = ordered;
		float avg;
		int sum=0, counter=0;
		
		while(t != NULL)
		{
			sum += t->info;
			counter ++;
			t = t->next;
		}
		avg = sum/counter;
		return avg;
	}

};

#endif