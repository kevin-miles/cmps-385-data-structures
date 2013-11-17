//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 6 Part 1
//				Due Date		October 16, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program uses user created libraries that implement stack
//          and queue through linked lists. Using these linked lists
//          the user provides an input to be tested if its a palindrome.
//          Each character is pushed into a stack and queue. The stack and
//          queue are popped and each character is evaluated to see if they
//          match. If they do not the user is notified they are not palindromes.
//          Otherwise the user is notified they are palindromes.
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
//include our own libraries
#include "QUEUELINK.h"
#include "STACKLINK.h"

using namespace std;
bool repeat(string question);
void palindrome(string sentence);

int main()
{
	string input;
	bool again = true;

	while(again)
	{
		cout << "Enter a sentence/phrase: ";
		getline(cin, input, '\n'); //\n is the delimiter 
		
		palindrome(input);
		again = repeat("CONTINUE(y/n)?");
		cout << endl;

	}

	system("pause");
	return 0;
}

/*
Name:     palindrome
Purpose:  takes a string input
		  pushes it into a stack linked list and also into a queue linked list.
		  pops out each list and compares contents.
		  if there is not a match then they are not palindromes.
		  if the list is empty then they are both palindromes.
		  the result "It is a palindrome" or "Not a palindrome"
		  is printed after evaluating the contents.
*/
//question should expect a YES or NO answer
void palindrome(string sentence)
{
	STACKLINK<char> S;
	QUEUELINK<char> Q;
	S.CreateStack();
	Q.CreateStack();

	char letter, a, b;

	for(int i=0; i<sentence.length(); i++)
	{
		letter = sentence[i];
		if(isalpha(letter))
		{
			letter = tolower(letter);
			S.Push(letter);
			Q.Push(letter);
		}
	}

	while(S.Empty()!=true)
	{
		a = S.Pop();
		b = Q.Pop();
		if(a != b)
		{
			break;
		}
	}
	if(S.Empty())
	{
		cout << "\tIt is a palindrome." << endl;
	}
	else
	{
		cout << "\tNot a palindrome." << endl;
	}
}

/*
Name:     repeat
Purpose:  takes a string question that is expected to have a YES or NO answer.
		  the function loops until the user enters 'N' or 'n' for NO and a false value is returned. 
		  Otherwise the user can enter 'Y' or 'y' for YES and a true value is returned. 
*/
//question should expect a YES or NO answer
bool repeat(string question)
{
	char answer;
	bool loopme = true;

	while(loopme)
	{
		cout << question;
		cin >> answer;
		cin.ignore(INT_MAX,'\n');
		answer = tolower(answer);

		if(answer == 'y')
		{
			loopme = false;
			return true;
		}
		else if(answer == 'n')
		{
			loopme = false;
			return false;
		}
		else
		{
			cout << endl << "INVALID INPUT!" << endl;
		}
	}
				
}
/*
Enter a sentence/phrase: Never Odd or Even
		It is a palindrome.
CONTINUE(y/n)?y

Enter a sentence/phrase: Murder for a jar of red rum
		It is a palindrome.
CONTINUE(y/n)?n

Press any key to continue . . .
*/