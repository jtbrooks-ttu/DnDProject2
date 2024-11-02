/*
	Title:   LinkedList.tpp
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/14/24
	Purpose: Doubly linked list for circular character display.
*/

#include "LinkedList.h"

using namespace std;
/*
	Title:   isEmpty
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Checks if list contains any nodes.
*/
template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (!head) //checks if head node exists
		return true;
	else
		return false;
}
/*
	Title:   getNode
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Returns value held in chosen node.
*/
template <typename T>
T LinkedList<T>::getNode(int pos)
{
	ListNode<T> *nodePtr;
	if (!head)
		return -1;
	else
	{
		if (pos == 0) // if chosen node is the head
			return head->value;
		nodePtr = head;
		int currentPos = 0;

		while (nodePtr != NULL && pos >= currentPos) // searches for node
		{
			if (pos == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;
		}
	}
	return -1;
}
/*
	Title:   appendNode
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Adds new node to the end of list.
*/
template <typename T>
int LinkedList<T>::appendNode(T val)
{
	ListNode<T> *newNode;
	ListNode<T> *nodePtr;

	newNode = new ListNode<T>; // initializes newNode
	newNode->value = val;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (!head) // list was empty
	{
		head = newNode;
		tail = newNode;
		return 1;
	}
	else // list contained other nodes
	{

		tail->next = newNode; //add onto end
		newNode->previous = tail; // doubly link
		tail = newNode; // set new tail
		tail->next = head; // circularly link
		head->previous = tail; // doubly & circular link
		return 2;
	}
}

/*
	Title:   deleteNode
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Deletes current node
*/
template <typename T>
void LinkedList<T>::deleteNode(ListNode<T> *val)
{
	ListNode<T> *nodePtr;
	ListNode<T> *previousNode;

	if (!head) // if list is empty
		return;

	if (head == val) // if the chosen node is the head
	{
		nodePtr = head->next;
		delete head;
		if (nodePtr != NULL) // if there are nodes left
		{
			head = nodePtr;
			head->previous = tail;
			tail->next = head;
		}
		else  				// list is now empty
			head = NULL;
	}
	else if (tail == val) // if chosen node is the tail
	{
		nodePtr = tail->previous;
		delete tail;
		if (nodePtr != NULL) // if there are nodes left
		{
			tail = nodePtr;
			tail->next = head;
			head->previous = tail;
		}
		else				// list is now empty
			tail = NULL;
	}
	else					// chosen node is in the middle
	{
		nodePtr = val->next;
		previousNode = val->previous;
		delete val;
		previousNode->next = nodePtr;
		nodePtr->previous = previousNode;
	}
}
/*
	Title:   ~LinkedList (Destructor)
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Deletes individual nodes before deleting the list.
*/
template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T> *nodePtr;
	ListNode<T> *nextNode;

	nodePtr = head;

	while (nodePtr != NULL) // iterates through list and deletes nodes
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}
/*
	Title:   begin
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Returns head node.
*/
template <typename T>
ListNode<T> *LinkedList<T>::begin()
{
	return head;
}
/*
	Title:   end
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Returns tail node.
*/
template <typename T>
ListNode<T> *LinkedList<T>::end()
{
	return tail;
}
/*
	Title:   setEnd
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Takes in pointer and sets tail to that pointer.
*/
template <typename T>
void LinkedList<T>::setEnd(ListNode<T> *ptr)
{
	this->tail = ptr;
}
/*
	Title:   setHead
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Takes in pointer and sets head to that pointer.
*/
template <typename T>
void LinkedList<T>::setHead(ListNode<T>* ptr){
	this->head = ptr;
}
	
/*
	Title:   split
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Finds midpoint and splits list into two halves.
*/
template <typename T>
ListNode<T> *LinkedList<T>::split(ListNode<T> *head)
{
	ListNode<T> *fast = head;
	ListNode<T> *slow = head;

	while (fast != nullptr && fast->next != nullptr) // checks if current or next nodes are null
	{
		fast = fast->next->next; // increment fast twice

		if (fast != nullptr) // if fast is not null, increment slow
		{
			slow = slow->next;
		}
	}

	ListNode<T> *temp = slow->next; // head for second list
	slow->next = nullptr; // splits lists
	return temp; 
}
/*
	Title:   merge
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Merges previously split lists.
*/
template <typename T>
ListNode<T> *LinkedList<T>::merge(ListNode<T> *first, ListNode<T> *second, const int sortDirection)
{
	// after merging is complete the new head is returned
	
	if (first == nullptr) // if list is empty return other list
		return second;
	if (second == nullptr)
		return first;

	
	if(sortDirection == 1){ // Ascending sort direction
	if (first->value < second->value) // overloaded < operator
	{
		first->next = merge(first->next, second, sortDirection); // recursively merge lists
		return first; 
	}
	else
	{
	
		second->next = merge(first, second->next, sortDirection); // recursively merge lists
		return second;
	}
	}
	else{ // Descending sort direction (rest is same as above)
	if (first->value > second->value)
	{
		first->next = merge(first->next, second, sortDirection);
		return first;
	}
	else
	{
		second->next = merge(first, second->next, sortDirection);
		return second;
	}
	}
}
/*
	Title:   MergeSort
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/24/24
	Purpose: Sorts singly linked list.
*/
template <typename T>
ListNode<T> *LinkedList<T>::MergeSort(ListNode<T> *head, const int sortDirection)
{
	if (head == nullptr || head->next == nullptr) // sorted or has one node
		return head;

	ListNode<T> *second = split(head); //splits list

	head = MergeSort(head, sortDirection); // recursively sort left list
	second = MergeSort(second, sortDirection); // recursively sort right list

	return merge(head, second, sortDirection); // merge lists
}
