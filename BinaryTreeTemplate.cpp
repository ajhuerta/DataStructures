// BinaryTreeTemplate.cpp : This file created by Anthony Huerta

//**********************************************************
// Both parts of hte assignment are completed in this file
//***********************************************************.

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Strcutre of the BST is created (very similar to the design used for the contact BST)
template<class T>
struct NodeTemplate
{
	T data;
	NodeTemplate<T>* left;
	NodeTemplate<T>* right;

	NodeTemplate<T>(T value)
	{
		data = value;
		left = NULL;
		right = NULL;
		
	}
}; 

// Initialization of BSTtemplate class which holds all needed member functions
template<class T>
class BSTtemplate
{

private:

	NodeTemplate<T>* root;
	int counter = 0;

	//private functions that handle insertion and displaying because a pointer perameter is needed to properly handle recursion
	NodeTemplate<T>* insertPrivate(T i, NodeTemplate<T>* p);
	void displayPrivate(NodeTemplate<T>* p);

public:
	//Constructor
	BSTtemplate();
	void insert(T i);
	void display();
	int nodeCounter();
};

template<class T>
BSTtemplate<T>::BSTtemplate() {
	root = NULL;
}

template<class T>
void BSTtemplate<T>::insert(T value)
{
	counter++;
	root = insertPrivate(value, root);
}

template<class T>
void BSTtemplate<T>::display() 
{
	displayPrivate(root);
}

//nodeCounter completes the 2nd part of the assignment, it keeps track of the number of nodes within the tree
template<class T>
int BSTtemplate<T>::nodeCounter() 
{
	return counter;
}

//insertPrivate inputs all the values the user gives based on where they fit into the tree
template<class T>
NodeTemplate<T>* BSTtemplate<T>::insertPrivate(T i, NodeTemplate<T>* rootptr) 
{
	if (rootptr == NULL) 
	{
		rootptr = new NodeTemplate<T>(i);
	}
	else if (i <= rootptr->data)
	{
		rootptr->left = insertPrivate(i, rootptr->left);
	}
	else if (i > rootptr->data) 
	{
		rootptr->right = insertPrivate(i, rootptr->right);
	}

	return rootptr;
}

//displayPrivate prints out all the values in order of least to greatest 
template<class T>
void BSTtemplate<T>::displayPrivate(NodeTemplate<T>* rootptr)
{
	if (rootptr != NULL)
	{
		displayPrivate(rootptr->left);
		cout << rootptr->data << endl;
		displayPrivate(rootptr->right);
	}
}


int main()
{
	cout << "Welcome to the Binary Search Tree Template Program!" << endl;
	cout << "===================================================" << endl << endl;

	cout << "First, a tree will be created with the int data type. . ." << endl << endl;

	// BST with int data type
	BSTtemplate<int> intTree;

	intTree.insert(20);
	intTree.insert(25);
	intTree.insert(5);
	intTree.insert(7);
	intTree.insert(3);
	intTree.display();
	cout << "The total number of nodes: " << intTree.nodeCounter() << endl;

	cout << endl << "Second, a tree will be created with the string data type. . ." << endl << endl;

	// BST with string data type
	BSTtemplate<string> stringTree;

	stringTree.insert("Hello");
	stringTree.insert("How");
	stringTree.insert("are");
	stringTree.insert("you");
	stringTree.insert("today");
	stringTree.insert("?");
	stringTree.display();
	cout << "The total number of nodes: " << stringTree.nodeCounter() << endl;

	cout << endl << "Lastly, a tree will be created with the double data type. . ." << endl << endl;

	// BST with double data type
	BSTtemplate<double> doubleTree;

	doubleTree.insert(9.8);
	doubleTree.insert(4.7);
	doubleTree.insert(99.2);
	doubleTree.insert(2.344);
	doubleTree.insert(3.14);
	doubleTree.insert(5.66);
	doubleTree.insert(22.4);
	doubleTree.display();
	cout << "The total number of nodes: " << doubleTree.nodeCounter() << endl;

	cout << endl << "Thank you for using the Binary Search Tree Template Program!" << endl << endl;
}
