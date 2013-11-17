//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 2 Part 4
//				Due Date		September 11, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program uses members of the <string> library to display 
//          the initial(s) of one, two, or three words in uppercase.
//          Error checks have also been implemented for fun. 
//          (Users can enter whatever they want without much issue to the
//          program.)
//----------------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*
	 Name:    get_words
	 Purpose: Asks user to enter a name and continues to loop until
			  the user enters input.
*/
void get_words(string& words)
{
	cout << "\tEnter a name: ";
	getline(cin, words);

	while(words.empty()) //loop until they get it right
	{
		cout << "\tERROR: Please enter a name!" << endl;

		cout << "\tEnter a name: ";

		getline(cin, words);
	}
}

/*
	 Name:    stupper
	 Purpose: Pased a string by reference. Converts that string to uppercase.
*/
void stupper(string& word)
{
	for(int i=0; i < word.length(); i++)
	{
		word[i] = toupper(word[i]);
	}
}

/*
	 Name:    print_initials
	 Purpose: Passed a word by value. Extracts the first letter of each word
			  and adds them to an initials placeholder that is capitalized
			  prior to being printed as output.
*/
void print_initials(string words)
{
	string initials;
	int location;

	initials += (words[0]); //take first letter

	location = words.find(' ');
	if(location > 0) //.find returns -1 if the find fails to find what it is searching for
	{
		initials += words[location+1]; //take first letter after space location
	}

	location = words.find(' ', location+1);
	if(location > 0) //.find returns -1 if the find fails to find what it is searching for
	{
		initials += words[location+1]; //take first letter after space location
	}

	stupper(initials); //make uppercase

	cout << "\tThe initial ";
	if(initials.length() > 2) { cout << "s "; }
	cout << "of " << words << " is " << initials << endl;
}


/*
	 Name: get_continue
	 Purpose: Asks user if they want to continue until they enter Y, y, N, n.
			  If not, it will continue to loop until they give a valid command.
*/
bool get_continue()
{
	char r;
		

	cout << "Continue (y/n)? ";
	cin.get(r);

	if(r=='n' || r=='N')
	{
		return false;
	}
	else if (r =='y' || r =='Y')
	{
		cin.ignore(); 
		return true;
	}
	else
	{
		//If this is exactly numeric_limits<streamsize>::max(), 
		//there is no limit: As many characters are extracted as 
		//needed until delim (or the end-of-file) is found.
		cin.ignore( numeric_limits <streamsize> ::max(), '\n');

		get_continue(); //call self
	}
}

int main()
{
	bool run = true;
	char input='Y';
	string name;

	while(run)
	{
		get_words(name);
		print_initials(name);

		if(!get_continue())
		{
			run = false; //exits the loop
		}
	}

	system("pause");
	return 0;
}

/*
		Enter a name: England
		The initial of England is E
Continue (y/n)? y
		Enter a name: New Mexico university
		The initial s of New Mexico university is NMU
Continue (y/n)? n
Press any key to continue . . .
*/