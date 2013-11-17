#ifndef QUEUELINKPACK
#define QUEUELINKPACK

using namespace std;

class QUEUELINK
{
	private: 
		struct NODE
		{
			string name;
			int age;
			NODE *next;
		} *queue;
	public:
		void CreateStack(){ queue = NULL; }
		void Push(string n, int x)
		{
			NODE *r, *last;
			r = new NODE;
			r -> age = x;
			r -> name = n;
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
		

		void Pop(string &name, int &age)
		{
			NODE *p = queue;

			if(queue != NULL) { 
				name = p -> name ;
				age = p -> age;
			}
			queue = p -> next;
			delete (p);
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
				cout << p -> name << "  "  << p -> age << " --> "; 
				p = p -> next;
			}
			cout << "NULL" << endl;
		}
};

#endif