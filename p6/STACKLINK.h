#ifndef STACKLINKPACK
#define STACKLINKPACK

template <class T>
class STACKLINK
{
	private: 
		struct NODE
		{
			T info;
			NODE *next;
		} *Stack;
	public:
		void CreateStack(){ Stack = NULL; }
		void Push(T x)
		{
			NODE *r;
			r = new NODE;
			r -> info = x;
			r -> next = Stack;
			Stack = r;
		}
		

		int Pop()
		{
			NODE *p = Stack;
			T x;
			if(Stack != NULL) { 
			 x = Stack -> info;
			}
			Stack = p -> next;
			delete (p);
			return x;
		}

		bool Empty()
		{
			if(Stack == NULL) { return true; }
			else { return false; }
		}
		
		void Display()
		{
			NODE * p = Stack;
			while(p != NULL)
			{
				cout << p -> info << " --> "; 
				p = p -> next;
			}
			cout << "NULL" << endl;
		}
};

#endif