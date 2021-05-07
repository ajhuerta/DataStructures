#include <iostream>
#include <string>
#include "ContactTree.h"
using namespace std;

ContactTree::ContactTree() {
	root = NULL;
}

void ContactTree::display() {
	displayPrivate(root);
}
void ContactTree::insert(long long phone, string mail) {
	root = insertPrivate(root, phone, mail);
}

ContactTree::ContactNode* ContactTree::insertPrivate(ContactNode* rootptr, long long phone, string mail) {
	//if Root is empty, user input is assigned directly to it
	if (rootptr == NULL) {

		rootptr = new ContactNode;
		rootptr->phoneNum = phone;
		rootptr->email = mail;
		rootptr->left = NULL;
		rootptr->right = NULL;
	}
	else if (rootptr->phoneNum > phone) {
		rootptr->left = insertPrivate(rootptr->left, phone, mail);
	}
	else if(rootptr->phoneNum < phone)
	{
		rootptr->right = insertPrivate(rootptr->right, phone, mail);
	}
	return rootptr;
}

//displayPrivate prints out all the values in the ContactTree in order from smallest phone number to largest phone number
void ContactTree::displayPrivate(ContactNode* rootptr) {
	if (rootptr == NULL)
	{
		return;
	}
	displayPrivate(rootptr->left);
	cout << rootptr->phoneNum << " " << rootptr->email << endl;
	displayPrivate(rootptr->right);
}