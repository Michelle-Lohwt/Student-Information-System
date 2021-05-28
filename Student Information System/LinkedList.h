#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#ifndef H_LINKEDLIST
#define H_LINKEDLIST

//<struct> nodeType
template <class Type>
struct nodeType {
	Type info[4];
	nodeType* link;
};

//***********************************************************
// This class specifies the members to implement an iterator
// to a linked list.
//***********************************************************
template <class Type>
class linkedListIterator {
public:
	linkedListIterator();
	//Default constructor
	//Postcondition: point = NULL

	linkedListIterator(nodeType<Type>*);
	//Parameterised Constructor
	//Postcondition: point = (what pass by pointer)

	linkedListIterator<Type> operator++(int);
	//Overload post-increment operator.
	//Postcodition: The iterator is advanced to the next node.

	bool operator != (const linkedListIterator<Type>&) const;
	//Overload the not-equal-to operator
	//Postcondition: Returns true if this iterator is not equal to
	//		the iterator specified by right, otherwise it returns
	//		false.

	nodeType<Type>* operator->() const;
	//Overload member access operator
	//Postcondition: Returns point (point points to somewhere)

private:
	nodeType<Type>* point;	//pointer to point to the current node
							//in the linked list
};

template <class Type>
linkedListIterator<Type>::linkedListIterator() {
	point = NULL;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type>* current) {
	point = current;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++(int u) {
	point = point->link;
	return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right)const {
	return (point != right.point);
}

template <class Type>
nodeType<Type>* linkedListIterator<Type>::operator->() const {
	return point;
}


//***********************************************************
// This class specifies the members to implement the basic
// properties of a linked list.
//***********************************************************
template <class Type>
class linkedList {
public:
	//Basic properties of a linked list
	linkedList();
	//Default constructor
	//Initialises the list to an empty state.
	//Postcondition: first = NULL, last = NULL

	~linkedList();
	//Destructor
	//Deletes all the nodes from the list
	//Postcondition: The list object is destroyed.

	bool isEmpty();
	//Function to determine whether the list is empty.
	//Postcondition: Returns true if the list is empty,
	//		otherwise it returns false.

	void print() const;
	//Function to output the data contained in each node.
	//Postcondition: Print out the data

protected:
	nodeType<Type>* first, * last;
};

template <class Type>
linkedList<Type>::linkedList() {
	first = NULL;
	last = NULL;
}

template <class Type>
linkedList<Type>::~linkedList() {
	nodeType<Type>* temp;

	while (first != NULL) {
		temp = first;
		first = first->link;
		delete temp;
	}
	last = NULL;
}

template <class Type>
bool linkedList<Type>::isEmpty() {
	return(first == NULL);
}

template <class Type>
void linkedList<Type>::print() const {

	nodeType<Type>* current = first;

	linkedListIterator<Type> ptr = linkedListIterator<Type>(current);

	cout << endl << setfill('~') << setw(20) << ' ' << endl;
	cout << "Printing" << endl;
	cout << setw(20) << ' ' << endl;

	cout << setiosflags(ios::left) << setfill(' ') << setw(50) << "Student name"
		<< setw(20) << "Matric number" << setw(10) << "Year" << setw(10) << "CGPA" << endl;

	while (ptr != NULL) {
		cout << setw(50) << ptr->info[0] <<
			setw(20) << ptr->info[1] <<
			setw(10) << ptr->info[2] <<
			setw(10) << ptr->info[3] << endl;
		ptr++;
	}
	cout << endl << endl;
	cout << setfill('-') << setw(120) << " ";
}
#endif
