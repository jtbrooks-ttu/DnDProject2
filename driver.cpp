/*
	Title:   driver.cpp
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/14/24
	Purpose: Contains main function. Contains and describes program flow.
*/
#include "LinkedList.h"
#include "Character.h"
#include <string>

using namespace std;

int main()
{
	LinkedList<Character> list;
	ListNode<Character> *nodePtr;
	ListNode<Character> *temp;
	ListNode<Character> *it;
	ListNode<Character> *end;
	Character newChar;
	int sortDirection;

	cout << string(80, '*') << "\n\t\tWELCOME TO DND CHARACTER SELECTION\n"
		 << string(80, '*') << endl;

	// input integer for our switch statement
	int choice = 0;

	while (choice != 6)
	{
		if (list.isEmpty()) // list is empty
			cout << endl
				 << "No characters found..." << endl
				 << endl;
		else // list has at least one node
		{
			cout << endl;
			cout << "******CURRENT CHARACTER******" << endl
				 << endl;
			cout << it->value << endl;
		}
		printMenu(); // prints menu to user
		cout << "Choice: ";
		choice = validateInt(choice, 1, 6); // validates choice
		switch (choice)
		{
		case 1: // Next Character
			it = it->next;
			break;
		case 2: // Previous Character
			it = it->previous;
			break;
		case 3: // Add Character
			cout << endl;
			cin.ignore();
			cin >> newChar;
			if (list.appendNode(newChar) == 1) // newChar is the only node
			{
				it = list.begin();
			}
			else // iterator is on newChar
			{
				it = it->next;
			}
			end = list.end(); // move tail
			break;
		case 4:					 // Delete Character
			list.deleteNode(it); // deletes current node
			it = list.begin();	 // reset iterator
			end = list.end();	 // reset end
			break;
		case 5: // Display List
			cout << endl
				 << "Choose sort direction: " << endl;
			cout << setw(6) << " " << " 1. Ascending" << endl;
			cout << setw(6) << " " << " 2. Decending" << endl;
			sortDirection = validateInt(sortDirection, 1, 2); // validates sortDIrection
			nodePtr = list.end();
			nodePtr->next = NULL;	// unlink end of list
			nodePtr = list.begin(); // nodePtr at head
			while (nodePtr != NULL) // unlink rest of list
			{
				nodePtr->previous = NULL;
				nodePtr = nodePtr->next;
			}
			list.setHead(list.MergeSort(list.begin(), sortDirection)); // takes in list as singly linked and returns new head
			nodePtr = list.begin();									   // nodePtr at head
			while (nodePtr != NULL)
			{ // finds new tail
				if (nodePtr->next == NULL)
				{
					list.setEnd(nodePtr);
				}

				nodePtr = nodePtr->next;
			}
			nodePtr = list.begin(); // nodePtr at head
			temp = nodePtr->next;
			while (nodePtr != list.end()) // relinks list
			{
				temp->previous = nodePtr;
				nodePtr = temp;
				temp = temp->next;
			}
			nodePtr = list.end();
			nodePtr->next = list.begin();
			nodePtr = list.begin();
			nodePtr->previous = list.end();
			cout << endl
				 << "******FULL CHARACTER LIST******" << endl;
			cout << endl;
			cout << list; // prints list using overloaded <<
			break;
		case 6: // Exit Program
			return 0;
			break;
		default:
			cout << "You shouldn't be here" << endl;
			break;
		}
	}
	return 0;
}