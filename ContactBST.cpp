// ContactBST.cpp : This file created by Anthony Huerta
#include <iostream>
#include<cstdlib>
#include "ContactTree.h"
using namespace std;

int main()
{
	ContactTree contacts;
	long long phoneNumber = 0;
	string emailAddress = "";
	bool userCheck = true;
	int userChoice = 0;

    cout << "Hello! Welcome to the Contact Binary Search Tree program" << endl;
	cout << "=========================================================" << endl;

	//While loop which continues to run until the User inputs a bad input or until option 4 ins selected.
	while (userCheck) {

		cout << "Please Select from one of the options below" << endl << endl;
		cout << "1. Add your phone number and email address" << endl;
		cout << "2. Add a new contact's phone number and email address" << endl;
		cout << "3. Print out all saved contacts" << endl;
		cout << "4. Close the program" << endl << endl;

		cin >> userChoice;

		if (userChoice == 1) {
			cout << "What is your phone number? (ex: 8004797755)" << endl;
			cin >> phoneNumber;
			cout << endl << "What is your email address? (ex: JaneDoe66@gmail.com)" << endl;
			cin >> emailAddress;
			contacts.insert(phoneNumber, emailAddress);

		}

		else if (userChoice == 2) {
			cout << "What is this Contact's phone number? (ex: 8004797755)" << endl;
			cin >> phoneNumber;
			cout << endl << "What is this Contact's email address? (ex: JaneDoe66@gmail.com)" << endl;
			cin >> emailAddress;
			contacts.insert(phoneNumber, emailAddress);
		}

		else if (userChoice == 3) {
			contacts.display();
		}
		else if (userChoice == 4) {
			userCheck = false;
		}
		else if (userChoice != 1 || userChoice != 2 || userChoice != 3 || userChoice != 4)
		{
			cout << "Incorrect input, Program is exiting" << endl;
			break;
		}
	}
	cout << endl << "Thank you for using the Contact Binary Search Tree program" << endl;
}
