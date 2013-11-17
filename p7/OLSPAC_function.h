#ifndef OLSPAC_function
#define OLSPAC_function

template <class T>
class OLS_function
{
private:
	struct NODE
	{
		T coefficient, power;
		NODE * next;
	};

	NODE * ordered;
public:
	void CreateOrdered(){ ordered = NULL; }
	
	//x = coefficient
	//y = power
	void Insert(T x, T y)
	{
		//insert x in an ordered linked list pointed by p
		NODE *t, *q, *r;
		r = new NODE;
		r->coefficient = x;
		r->power = y;

		if(ordered == NULL) //list is empty
		{
			ordered=r;
			r->next = NULL;
		}
		else
		{
			t=q=ordered;
			//find insertion place
			while(t != NULL && r->power <  t->power) 
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

//needs to be float for pow function input
float Compute_Function(float v)
{
	NODE * t = ordered;
	float answer=0;

	while(t != NULL)
	{
		answer += ((t->coefficient) * pow (v, t->power));
		t = t->next;
	}

	return answer;
}

void Display()
{
	cout << "This is your function F(x)" <<endl;
	cout << "\t F(x) = ";
	NODE * t = ordered, * q;
	while(t != NULL)
	{
		q = t;
		cout << q->coefficient << "x^" << q->power;
		if(t->next != NULL) { cout << " + "; }
		t = t->next;
	}
	cout << endl;
}


};

#endif