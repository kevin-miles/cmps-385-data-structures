//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 1 Part 2
//				Due Date		September 4, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: This program uses a struct(Person) containing a string name, 
//          int age, and float gpa to copy a file's contents directly into
//          an array of type Person. The program displays the contents,
//          identifies and prints all teenager's names, the average GPA,
//          and average Age.
//----------------------------------------------------------------------	
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Person {
	string name;
	int age;
	float gpa;
};

/*
	 Name: Copy
	 Purpose: Opens a file of an unknown size and loads into into an array of type Person.
	          Is passed the filename and array to be loaded by the function call.
*/
void Copy(string fname, Person b[])
{
	int count = 0;
	fstream file;
	file.open(fname, ios::in);
	file >> b[count].name >> b[count].age >> b[count].gpa;
	count++;
	while(!file.eof())
	{
		file >> b[count].name >> b[count].age >> b[count].gpa;
		count++;
	}
	file.close();
}

/*
	 Name: Display
	 Purpose: Prints the contents of an array of a known size that is type Person.
	          NOTE: This function is overloaded.
*/
void Display(Person b[])
{
	cout << "\tName" << "\tAge" << "\tGpa" << endl;
	cout << "\t-----------------------" << endl;

	cout << fixed << setprecision(2);
	//floats will display two decimal places always

	//array size is known
	for(int i=0; i<5; i++)
	{
		
		cout << "\t" << b[i].name << "\t" << b[i].age << "\t" << b[i].gpa << endl;
	}
}

/*
	 Name: Display
	 Purpose: Prints the average age and gpa. Is passed age and gpa through function call.
	          NOTE: This function is overloaded.
*/
void Display(float avgGpa, float avgAge)
{
	cout << "The GPA average is: " << avgGpa << endl;
	cout << "The AGE average is: " << avgAge << endl;
}

/*
	 Name: DisplayTeens
	 Purpose: Checks the ages of the contents of an array of type Person.
	          Array size is known. Prints the names of anyone under 20 years.
*/
void DisplayTeens(Person b[])
{
	cout << "This is the list of teenagers" << endl;
	//array size known
	for(int i=0; i<5; i++)
	{
		if (b[i].age < 20)
		{
			cout << "\t" << b[i].name;
		}
	}
	cout << endl; //formatting
}

/*
	 Name: AverageGpa
	 Purpose: Calculates the average gpa from an array of type Person that is a known size. 
	          The average is passed by reference to variable given at the function call.
*/
void AverageGpa(Person b[], float& gpaAvg)
{
	float average=0;

	//array size known
	for(int i=0; i<5; i++)
	{
		average += b[i].gpa;
	}

	//array size known(5)
	gpaAvg = average/5;
}

/*
	 Name: AverageAge
	 Purpose: Returns the average age from an array of type person that is a known size.
*/
float AverageAge(Person b[])
{
	float average=0;

	//array size known
	for(int i=0; i<5; i++)
	{
		average += b[i].age;
	}

	//array size known(5)
	return average/5;
}

int main()
{

	Person a[5];

	Copy("data.txt", a);

	Display(a);

	DisplayTeens(a);

	float GpaAve;
	AverageGpa(a, GpaAve);

	float AgeAve;
	AgeAve = AverageAge(a);

	Display(GpaAve, AgeAve);

	system("pause");
	return 0;
}

/*
		Name    Age     Gpa
		-----------------------
		Michael 33      3.30
		Joseph  44      3.70
		Ruslan  19      2.90
		Joel    17      3.00
		Frank   21      3.20
This is the list of teenagers
		Ruslan  Joel
The GPA average is: 3.22
The AGE average is: 26.80
Press any key to continue . . .

*/