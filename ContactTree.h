#pragma once
#include <string>
#include<iostream>

using namespace std;
class ContactTree {
private:

	//Defines the structure of the Binary Search tree,
	//long long data type is used because int is not large enough to hold all phone numbers
	struct ContactNode {
		long long phoneNum;
		string email;
		ContactNode* left = NULL;
		ContactNode* right = NULL;
	};


	ContactNode* root;
	
	//private functions that handle insertion and displaying because a pointer perameter is needed to properly handle recursion
	ContactNode* insertPrivate(ContactNode* rootptr, long long phone, string mail);
	void displayPrivate(ContactNode* root);
public:
	//Constructor
	ContactTree();
	void insert(long long phone, string mail);
	void display();
	
};

