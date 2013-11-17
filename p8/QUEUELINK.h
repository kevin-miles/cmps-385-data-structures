#ifndef QUEUELINKPACK
#define QUEUELINKPACK

using namespace std;

class QUEUELINK
{
	private: 
struct MONTH
{
	string name;
	int days;
};

struct NODE
{
	MONTH month;
	NODE* next;
}* queue;
	public:
		void CreateStack(){ queue = NULL; }
		void Push(string m, int d)
		{
			NODE *r, *last;
			r = new NODE;
			r->month. = x;
			r -> next = NULL;
			if(queue == NULL)
			{
				//insert first item 
				queue = r;
			}
			else 
			{
				//queue exists and x must be inserted at rear
				last = queue;
				while(last->next != NULL)
				{
					last = last->next;
				}
				last->next = r;
			}
		}
		

		int Pop()
		{
			NODE *p = queue;
			T x;
			if(queue != NULL) { 
			 x = queue -> info;
			}
			queue = p -> next;
			delete (p);
			return x;
		}

		bool Empty()
		{
			if(queue == NULL) { return true; }
			else { return false; }
		}
		
		void Display()
		{
			NODE * p = queue;
			while(p != NULL)
			{
				cout << p -> info << " --> "; 
				p = p -> next;
			}
			cout << "NULL" << endl;
		}
};

#endif