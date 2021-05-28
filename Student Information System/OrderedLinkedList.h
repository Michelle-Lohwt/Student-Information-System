#pragma once
#include "LinkedList.h"
#include "UnorderedLinkedList.h"
using namespace std;

//***********************************************************
// This class specifies the members functions that implement
// basics properties of an ordered linked list.
//***********************************************************
template <class Type>
class orderedLinkedList : public unorderedLinkedList<Type> {
public:
	void insert(const Type*);
	//Function to insert a new node in order (highest
	// CGPA) in the list.
};

//Insert a new node
template <class Type>
void orderedLinkedList<Type>::insert(const Type* newInfo) {

	nodeType<Type>* current = NULL;
	nodeType<Type>* trailCurrent = NULL;
	nodeType<Type>* newNode = new nodeType<Type>;	//create a new node

	newNode->info[0] = *(newInfo);
	newNode->info[1] = *(newInfo + 1);
	newNode->info[2] = *(newInfo + 2);
	newNode->info[3] = *(newInfo + 3);
	newNode->link = NULL;

	if (this->isEmpty()) {	// Case 1 - The list is initially empty
		this->first = newNode;
		this->last = newNode;
	}
	else {
		// Case 2 - The list is not Empty
		current = this->first;

		//Search for the correct node
		while (current != NULL) {
			if (newNode->info[3] >= current->info[3])
				break;
			else {
				trailCurrent = current;
				current = current->link;
			}
		}

		//if the correct node is the first node
		if (current == this->first) {
			newNode->link = this->first;
			this->first = newNode;	//newNode become the first node
		}
		else {
			// Case 3- The list is not Empty, and the student CGPA to be inserted is higher than the first node in the list.
			// The node to be inserted somewhere is the list
			newNode->link = current;
			trailCurrent->link = newNode;
			if (current == NULL)
				this->last = newNode;
		}
	}
}
