#pragma once
#include "LinkedList.h"
using namespace std;

//***********************************************************
// This class specifies the members functions that require
// user's input, and implement basics properties of an 
// unordered linked list.
//***********************************************************
template <class Type>
class unorderedLinkedList : public linkedList<Type> {
public:
	//Functions that require user's input
	void selection();
	//Function that requires user to select to perform 
	//	insert new node, deleting node, 
	//	searching/ retrieving node or quit selection

	string* input(string*);
	//Function that requires user to add information


//Implement basics properties of an unordered linked list
	virtual void insert(const Type*);
	//Fuction to insert new node at the end of the list.
	//Function overriding

	void deleteNode(const Type);
	//Function to delete a node from the list

	void search(const Type);
	//Function to determine whether the item user is 
	//	searching for is in the list.
};

template <class Type>
void unorderedLinkedList<Type>::selection() {
	Type key;
	string select = "0", infoInput[4], * returned;

	while (select != "4") {
	Reselect:
		cout << endl << setfill('-') << setw(20) << ' ' << endl;
		cout << "Selection" << endl;
		cout << setw(20) << ' ' << endl;
		cout << "1. Add information" << endl;
		cout << "2. Delete information" << endl;
		cout << "3. Search/ Retrieve information" << endl;
		cout << "4. Quit selection" << endl;
		cout << "Select: ";

		getline(cin, select);	//User select to delete or search node

		if (select != "1" && select != "2" && select != "3" && select != "4") {
			cout << "Wrong number!" << endl;
			goto Reselect;
		}
		cout << endl << endl;

		switch (stoi(select)) {
		case 1: {
			//Insert a new node
			cout << "Add information is selected." << endl << endl;
			returned = input(infoInput);
			insert(returned);
			this->print();
			break;
		}
		case 2: {
			//Delete node
			cout << "Delete information is selected." << endl << endl;
			cout << "*****Cautious!!*****" << endl;
			cout << "Deletion will delete the student's information (name, matric, year, cgpa)" << endl << endl;
			cout << "You may enter the **matric** number for deletion only." << endl;
			cout << "Enter the matric number to be deleted: ";

			cin.ignore(0, '\n');
			getline(cin, key);
			cout << endl << endl;
			deleteNode(key);
			this->print();
			break;
		}
		case 3: {
			//Search node
			cout << "Search/ Retrieve information is selected." << endl << endl;
			cout << "You may enter the student's **name** for information retrieving only." << endl;
			cout << "Enter the name to be searched/ retrieved: ";

			cin.ignore(0, '\n');
			getline(cin, key);
			cout << endl << endl;
			search(key);
			this->print();
			break;
		}
		case 4: {
			//Quit selection
			cout << "Quit selection......" << endl << endl;
			break;
		}
		}//end switch
	}//end while
}//end selection

template <class Type>
string* unorderedLinkedList<Type>::input(string* infoInput) {
	cout << "Enter the full name: ";
	getline(cin, infoInput[0]);

	cout << "Enter the matric: ";
	getline(cin, infoInput[1]);

	cout << "Enter the year: ";
	getline(cin, infoInput[2]);

	cout << "Enter the CGPA: ";
	getline(cin, infoInput[3]);

	cout << endl;
	return infoInput;
}

//Insert a new node
template <class Type>
void unorderedLinkedList<Type>::insert(const Type* newInfo) {

	nodeType<Type>* newNode = new nodeType<Type>;	//create new node

	newNode->info[0] = *(newInfo);
	newNode->info[1] = *(newInfo + 1);
	newNode->info[2] = *(newInfo + 2);
	newNode->info[3] = *(newInfo + 3);
	newNode->link = NULL;

	if (this->isEmpty()) {	//if the list is empty, 
							//	set newNode to be the first and last node in the list
		this->first = newNode;
		this->last = newNode;
	}
	else {
		//the list is not empty, insert newNode after last
		this->last->link = newNode;
		this->last = newNode;			//set the newNode as last node
	}
}//End insert

//Delete a node
template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type deleteItem) {

	nodeType<Type>* current = NULL;			//pointer to traverse the list
	nodeType<Type>* trailCurrent = NULL;	//pointer before current

	cout << endl << setfill('-') << setw(20) << ' ' << endl;
	cout << "Deletion" << endl;
	cout << setw(20) << ' ' << endl;


	if (this->isEmpty())	//Case 1 - The list is empty
		cout << "The list is empty, nothing can be deleted." << endl;
	else {
		//The list is not empty
		current = this->first;					//current points to first node

		//Search for the correct node
		while (current != NULL) {
			if (current->info[1] == deleteItem)	//if the current node information is the same
				break;							//information as the user input-ed to delete, break the loop
			else {
				trailCurrent = current;			//else advance to the next node
				current = current->link;
			}
		}//end while


		if (current == this->first) {
			//Case 2 - The node to be deleted is the first node

			cout << "Matric is found in the first node." << endl;
			trailCurrent = current;				//trailCurrent points to the first node
			this->first = this->first->link;	//advance first to next node
			current = this->first;				//current point to first node
			delete trailCurrent;				//deallocate the original first node
			cout << "Information deleted." << endl << endl;
		}
		else {
			//The node to be deleted is not the first node

			if (current == this->last) {
				//Case 3 - The node to be deleted is the last node

				cout << "Matric is found in the last node." << endl;
				this->last = trailCurrent;		//last points to the node before current
				trailCurrent->link = NULL;		//set the node before current to NULL
				delete current;					//deallocate the original last node
				cout << "Information deleted." << endl << endl;
			}
			else {
				//The node is somewhere in the middle of the list OR it is not in the list

				if (current == NULL) {
					//Case 4 - The list does not contain the node with the given info
					cout << "The item to be deleted is not in the list." << endl;
				}
				else {
					//The node is somewhere in the middle of the list
					cout << "Matric is found." << endl;
					trailCurrent->link = current->link;
					delete current;
					cout << "Information deleted." << endl << endl;
				}
			}//end if-else-if-else-if-else
		}//end if-else-if-else
	}//end if-else
}//end deleNode


//Search a node
template <class Type>
void unorderedLinkedList<Type>::search(const Type searchItem) {

	nodeType<Type>* current;
	bool found = false;

	cout << endl << setfill('-') << setw(20) << ' ' << endl;
	cout << "Searching/ Retrieving" << endl;
	cout << setw(20) << ' ' << endl;

	current = this->first;	//current points to the first node

	//check if the list is empty
	if (this->isEmpty()) {
		cout << "The list is empty." << endl;
	}
	else {
		//the list is not empty

		while (current != NULL && !found) {	//find the node where the name user input-ed
			if (current->info[0] == searchItem)
				found = true;
			else
				current = current->link;
		}//end while

		//if name is found, print the student's information
		if (found) {
			cout << "The name is found." << endl;
			cout << setfill(' ') << setw(50) << "Student name" << setw(20) << "Matric number" << setw(10) << "Year" << setw(10) << "CGPA" << endl;

			cout << setw(50) << current->info[0] <<
				setw(20) << current->info[1] <<
				setw(10) << current->info[2] <<
				setw(10) << current->info[3] << endl << endl;
		}
		else	//no name is found
			cout << "No name is found." << endl << endl;
	}// end else
}// end search
