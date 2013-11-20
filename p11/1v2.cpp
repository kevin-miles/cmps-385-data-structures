//----------------------------------------------------------------------
//				Name			Kevin Miles
//				Course			CMPS 385
//				Project			No. 11 Part 1
//				Due Date		November 20, 2013
//				Professor		Ray Ahmadnia
//
// Purpose: Using a modified binary search tree library a bank program was
// implemented. It abstracts the binary search tree into a functional 'bank'
// interface that the user interact with. In this program a menu is displayed
// giving users options to add, display, show balance, deposit, withdraw, and 
// close an account.The user is given the ability to exit the program after each 
// given input.
//----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include "BSTPACv2.h"
#include <fstream>
#include <string>

using namespace std;

void displayBalance(BST<int> B);
void displayAll(BST<int> B);
void depositFunds(BST<int> B);
void withdrawFunds(BST<int> B);
void closeAccount(BST<int> B);
void openAccount(BST<int> B);

int main()
{
	BST<int> B;
	int r;
	fstream f;
	int bal, id;
	string name;

	f.open("data.txt", ios::in);

	f >> id >> name >> bal;
	while (!f.eof())
	{
		B.Insert(id, name, bal);
		f >> id >> name >> bal;
	}
	f.close();


	bool again;
	string leftover;
	char selection, c;
	cout << "--------- Bank of California ---------" << endl;
	cout << "a.\tDisplay all accounts" << endl;
	cout << "b\tShow my balance" << endl;
	cout << "c.\tDeposit" << endl;
	cout << "d.\tWithdraw" << endl;
	cout << "e.\tClose account" << endl;
	cout << "f.\tOpen a new account" << endl;
	cout << endl;
	do
	{
		do
		{
			cout << "Please enter your choice(a-f):";
			cin >> selection;
			getline(cin, leftover, '\n'); //gets rid of the rest of the input
		} while (selection != 'a' && selection != 'b' && selection != 'c' && selection != 'd' && selection != 'e' && selection != 'f');

		cout << endl;

		switch (selection)
		{
		case 'a':
			displayAll(B);
			break;
		case 'b':
			displayBalance(B);
			break;
		case 'c':
			depositFunds(B);
			break;
		case 'd':
			withdrawFunds(B);
			break;
		case 'e':
			closeAccount(B);
			break;
		case 'f':
			openAccount(B);
			break;
		}
		cout << endl;

		do
		{
			cout << "CONTINUE(y/n)?";
			cin >> c;
			getline(cin, leftover, '\n'); //gets rid of the rest of the input
		} while (c != 'y' && c != 'n');

		if (c == 'y'){ again = true; cout << endl; }
		else { again = false; }

	} while (again == true);

	system("pause");
	return 0;
}
/*
--------- Bank of California ---------
a.      Display all accounts
b       Show my balance
c.      Deposit
d.      Withdraw
e.      Close account
f.      Open a new account

Please enter your choice(a-f):a

ID      NAME    BALANCE
Tory    11      1111
Laura   22      1222
Maria   33      1333
Andre   44      1444
Carlo   55      1555
Alison  66      1666

CONTINUE(y/n)?y

Please enter your choice(a-f):b

Enter your ID number: 22
Laura, you have $1222 in your account.

CONTINUE(y/n)?y

Please enter your choice(a-f):e

Enter the ID number of the account you wish to close: 22
Account 22 is now closed.

CONTINUE(y/n)?y

Please enter your choice(a-f):a

ID      NAME    BALANCE
Tory    11      1111
Maria   33      1333
Andre   44      1444
Carlo   55      1555
Alison  66      1666

CONTINUE(y/n)?n
Press any key to continue . . .
*/

void displayBalance(BST<int> B)
{
	int id;
	cout << "\tEnter your ID number: ";
	cin >> id;
	B.DisplayBalance(id);
}

void displayAll(BST<int> B)
{

	cout << "ID\t" << "NAME\t" << "BALANCE\t" << endl;
	B.DisplayInorder();
}

void depositFunds(BST<int> B)
{
	int id, amount;
	cout << "\tEnter the ID number of the account you wish to deposit funds into: ";
	cin >> id;
	cout << "\tPlease enter the amount you wish to deposit: ";
	cin >> amount;
	B.DepositFunds(id, amount);
}

void withdrawFunds(BST<int> B)
{
	int id, amount;
	cout << "\tEnter the ID number of the account you wish to winthraw funds from: ";
	cin >> id;
	cout << "\tPlease enter the amount you wish to withdraw: ";
	cin >> amount;
	B.WithdrawFunds(id, amount);
}


void closeAccount(BST<int> B)
{
	int id;
	cout << "\tEnter the ID number of the account you wish to close: ";
	cin >> id;
	B.Delete(id);
	cout << "\tAccount " << id << " is now closed." << endl;
}

void openAccount(BST<int> B)
{
	int id, balance;
	string name;
	cout << "\tEnter the name: ";
	cin >> name;
	cout << "\tEnter the balance: ";
	cin >> balance;
	cout << "\tEnter the new ID: ";
	cin >> id;
	B.Insert(id, name, balance);
}
