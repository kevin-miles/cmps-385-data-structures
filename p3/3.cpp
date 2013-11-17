//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 3 Part 3
//				Due Date		September 18, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program gets a users input of a sentence. It extracts each character
//          and places it into a stack of either uppercase, lowercase, or vowels depending
//          if it is one or not. Each stack is then printed to the screen.
//----------------------------------------------------------------------
#include "STACK.h" //include our own stack library
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

bool isvowel(char c);
void stack_upper_lower_vowels(string input);

int main()
{
	string input;
	cout << "Enter a sentence: ";
	getline(cin, input, '\n');
	//third input is a delimiting sequence. the \n will be discarded
	//so cin.ignore(); doesent have to be used 

	stack_upper_lower_vowels(input);
	system("pause");
	return 0;
}
/*
	Name: isvowel
	Purpose: takes a character. returns true if character is a vowel. returns false otherwise.
*/
bool isvowel(char c)
{
	if(c=='A' || c== 'a' || c=='E' || c=='e' || c=='I' || c=='i' || c=='O' || c=='o' || c=='U' || c=='u')
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	Name: stack_upper_lower_vowels
	Purpose: takes a string. places each character of the string into an uppercase stack,
			 lowercase stack, or vowel stack if any of them are. 
*/
void stack_upper_lower_vowels(string input)
{
	STACK<char, 10> Temp, Upper, Lower, Vowel;
	char c;

	//initialize stacks
	Temp.createStack();
	Upper.createStack();
	Lower.createStack();
	Vowel.createStack();


	cout << input << endl;
	//loop up to the string input length
	//we are not guaranteed a \0 
	for(int i=0; i < input.length(); i++)
	{
		if(isupper(input[i]))
		{
			Upper.pushStack(input[i]);
		}
		if(islower(input[i]))
		{
			Lower.pushStack(input[i]);
		}
		if(isvowel(input[i]))
		{
			Vowel.pushStack(input[i]);
		}
	}

	
	//print stack contents by temporarily moving them into the Temp
	//stack and printing them there to reverse their order as per project
	//requirements
	cout << "\tUppercase Letters: ";
	while(!Upper.emptyStack())
	{
		c = Upper.popStack();
		Temp.pushStack(c);
	}
	while(!Temp.emptyStack())
	{
		c = Temp.popStack();
		cout << c << " ";
	}
	cout << endl;

	//same as above for lowercase letters
	cout << "\tLowercase Letters: ";
	while(!Lower.emptyStack())
	{
		c = Lower.popStack();
		Temp.pushStack(c);
	}
	while(!Temp.emptyStack())
	{
		c = Temp.popStack();
		cout << c << " ";
	}
	cout <<  endl;

	//same as above for vowels
	cout << "\tVowels: ";
	while(!Vowel.emptyStack())
	{
		c = Vowel.popStack();
		Temp.pushStack(c);
	}
	while(!Temp.emptyStack())
	{
		c = Temp.popStack();
		cout << c << " ";
	}
	cout <<  endl;


}

/*
Enter a sentence: Today Is Wed Sept 11
	Uppercase Letters: T I W S 
	Lowercase Letters: o d a y s e d e p t 
	Vowels: o a I e e 
*/
