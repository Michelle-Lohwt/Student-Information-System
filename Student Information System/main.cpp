#include <iostream>
#include <string.h>
#include <iomanip>
#include "OrderedLinkedList.h"

using namespace std;

void showMenu(string& choice) {
Input:
	cout << endl << setfill('-') << setw(20) << ' ' << endl;
	cout << "C++ Linked list" << endl;
	cout << setw(20) << ' ' << endl;

	cout << "\t\t1. Ordered Linked List" << endl;
	cout << "\t\t2. Unordered Linked List" << endl << endl;

	cout << "Enter your choice: ";
	getline(cin, choice);
	if (choice != "1" && choice != "2") {
		cout << "Invalid input!" << endl;
		goto Input;
	}
	cout << endl << endl;
}

int main() {
	string choice;
	unorderedLinkedList <string> unordered;
	orderedLinkedList <string> ordered;

	//Start

	//Choose to do ordered linked list or unordered linked list
	showMenu(choice);

	switch (stoi(choice)) {
	case 1: {
		cout << endl << setfill('-') << setw(50) << ' ' << endl;
		cout << "Ordered Linked List" << endl;
		cout << setw(50) << ' ' << endl;

		ordered.selection();	//User's selection
		cout << "**Final Result**" << endl;
		ordered.print();		//Print out the final result of the linked list
		break;
	}
	case 2: {
		//Unordered Linked List
		cout << endl << setfill('-') << setw(50) << ' ' << endl;
		cout << "Unordered Linked List" << endl;
		cout << setw(50) << ' ' << endl;

		unordered.selection();	//User's selection
		cout << "**Final Result**" << endl;
		unordered.print();		//Print out the final result of the linked list
		break;
	}
	}

	cout << "\n\nEnding the program..." << endl << endl;
	return 0;
	//The program ends by triggering the destructor
}
