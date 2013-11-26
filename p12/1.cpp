//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 12 Part 1
//				Due Date		December 24, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program overloads the operators +,-,*,/ to provide the
// the functionality of adding, subtracting, multiplying, and dividing to
// fractions. The fractions are provided as input from the user and the 
// program prints out the equations with each operator that was overloaded
// and the answer.
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;


class fract
{
private:
	int n, d;
public:
	void read()
	{
		cout << "Enter a fraction: ";
		cin >> n; 	
		cin.ignore();
		cin >> d;
	}

	void whoami()
	{
		cout << n << '/' << d;
	}
	friend void operator++ (fract &p)
	{
		fract r;
		r.n = p.n + p.d;
		r.d = p.d;
		p.n = r.n;
		p.d = r.d;
	}

	friend void operator-- (fract &p)
	{
		fract r;
		r.n = p.n - p.d;
		r.d = p.d;
		p.n = r.n;
		p.d = r.d;
	}

	fract operator* (fract g)
	{
		fract q;
		q.n = n * g.n;
		q.d = d * g.d;
		return q;
	}

	fract operator/ (fract p)
	{
		fract r;
		r.n = n * p.d;
		r.d = d * p.n;
		return r;
	}

	friend fract operator+ (fract p, fract q)
	{
		fract s;
		s.n = (p.n*q.d) + p.d*q.n;
		s.d = p.d*q.d;
		return s;
	}

	friend fract operator- (fract p, fract q)
	{
		fract s;
		s.n = (p.n*q.d) - p.d*q.n;
		s.d = p.d*q.d;
		return s;
	}

};

int main()
{
	fract a, b, current;
	a.read();
	b.read();
	
	cout << '\t';
	a.whoami(); cout << " + "; b.whoami(); cout << " = ";
	current = a + b; current.whoami();
	cout << endl;

	cout << '\t';
	a.whoami(); cout << " - "; b.whoami(); cout << " = "; 
	current = a - b; current.whoami();
	cout << endl;

	cout << '\t';
	a.whoami(); cout << " * "; b.whoami(); cout << " = "; 
	current = a * b; current.whoami();
	cout << endl;

	cout << '\t';	
	a.whoami(); cout << " / "; b.whoami(); cout << " = ";
	current = a / b; current.whoami();
	cout << endl;
	
	cout << '\t';
	b.whoami(); cout << "++ "; cout << " = "; 
	b++; b.whoami();
	cout << endl;

	cout << '\t';
	a.whoami(); cout << "-- "; cout << " = ";
	a--; a.whoami();
	cout << endl;

	system("pause");
	return 0;
}
/*
Enter a fraction: 4/5
Enter a fraction: 6/7
	4/5 + 6/7 = 58/35
	4/5 - 6/7 = -2/35
	4/5 * 6/7 = 24/35
	4/5 / 6/7 = 28/30
	6/7++  = 13/7
	4/5--  = -1/5
Press any key to continue . . .
*/