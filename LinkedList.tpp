/*
	Title:   LinkedList.cpp
	Author:  J.T. Brooks & Carson Alfaro & Not Max >:/
	Date:    10/14/24
	Purpose: Doubly linked list for circular character display.
*/

#include "LinkedList.h"

using namespace std;

template <typename T>
bool LinkedList<T>::isEmpty()
{
	if (!head)
		return true;
	else
		return false;
}
template <typename T>
int LinkedList<T>::getLength()
{
	int counter = 0;
	ListNode<T> *nodePtr;

	nodePtr = head;

	while (nodePtr != tail)
	{
		counter++;
		nodePtr = nodePtr->next;
		if (nodePtr == tail)
			counter++;
	}
	return counter;
}

template <typename T>
T LinkedList<T>::getNodeValue(int position)
{
	ListNode<T> *nodePtr;
	if (!head)
		return -1;
	else
	{
		if (position == 0)
			return head->value;
		nodePtr = head;
		int currentPos = 0;

		while (nodePtr != NULL && position >= currentPos)
		{
			if (position == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;
		}
	}
	return -1;
}

template <typename T>
int LinkedList<T>::appendNode(T val)
{
	ListNode<T> *newNode;
	ListNode<T> *nodePtr;

	newNode = new ListNode<T>;
	newNode->value = val;
	newNode->next = NULL;
	newNode->previous = NULL;

	if (!head)
	{
		head = newNode;
		tail = newNode;
		return 1;
	}
	else
	{

		tail->next = newNode;
		newNode->previous = tail;
		tail = newNode;
		return 2;
	}
}

template <typename T>
void LinkedList<T>::insertNode(int position, T num)
{
	ListNode<T> *nodePtr;
	ListNode<T> *newNode;

	newNode = new ListNode<T>;
	newNode->value = num;

	if (!head)
	{
		if (position != 0)
		{

			cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
		}
		head = newNode;
		tail = newNode;
	}
	else
	{
		nodePtr = head;
		int nodeCount = 0;
		if (position == 0)
		{
			newNode->next = head;
			head->previous = newNode;
			head = newNode;
		}
		while (nodePtr != tail && nodeCount < position)
		{
			nodeCount++;
			if (nodeCount == position)
				break;
			nodePtr = nodePtr->next;
		}

		if (nodePtr->next == NULL)
			tail = newNode;

		newNode->next = nodePtr->next;
		newNode->previous = nodePtr;

		nodePtr->next = newNode;

		if (newNode->next)
		{
			nodePtr = newNode->next;
			nodePtr->previous = newNode;
		}
	}
}
template <typename T>
void LinkedList<T>::deleteNode(ListNode<T> *val)
{
	ListNode<T> *nodePtr;
	ListNode<T> *previousNode;

	if (!head)
		return;

	if (head == val)
	{
		nodePtr = head->next;
		delete head;
		if (nodePtr != NULL)
		{
			head = nodePtr;
			head->previous = tail;
			tail->next = head;
		}
		else
			head = NULL;
	}
	else if (tail == val)
	{
		nodePtr = tail->previous;
		delete tail;
		if (nodePtr != NULL)
		{
			tail = nodePtr;
			tail->next = head;
			head->previous = tail;
		}
		else
			tail = NULL;
	}
	else
	{
		nodePtr = val->next;
		previousNode = val->previous;
		delete val;
		previousNode->next = nodePtr;
		nodePtr->previous = previousNode;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	ListNode<T> *nodePtr;
	ListNode<T> *nextNode;

	nodePtr = head;

	while (nodePtr != NULL)
	{

		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

template <typename T>
ListNode<T> *LinkedList<T>::begin()
{
	return head;
}

template <typename T>
ListNode<T> *LinkedList<T>::end()
{
	return tail;
}
template <typename T>
void LinkedList<T>::mergeSort(int end){
	cout << " TODO: MAKE MERGE SORT WORK " << endl; }  
// 	int midIndex;
// 	int counter = 0;
// 	ListNode<T>* mid = NULL;
// 	ListNode<T>* countPtr;

   
//    if (head != tail)  //recursive case (when beg == end then that is base case) 
//    {
// 		midIndex = (beg + end) / 2;  // Find the midpoint in the partition
// 		countPtr = head;
// 		while(counter != midIndex){
// 					countPtr = countPtr->next;
// 					counter++;
// 				}
// 		mid = countPtr;
// 		mergeSort(mid); //recursively sort left partition
// 		mergeSort(mid + 1, end); //recursively sort right partition

// 		// Merge left and right partition in sorted order
// 		Merge(list, beg, mid, end);
//    }
// }

// void Merge(int list[], int beg, int mid, int end) {
//    int mergedSize = end - beg + 1;                // Size of merged partition
//    int mergePos = 0;                          // Position to insert merged number
//    int leftPos = 0;                           // Position of elements in left partition
//    int rightPos = 0;                          // Position of elements in right partition
//    int* mergedNumbers = new int[mergedSize];  // Dynamically allocates temporary listay
//                                               // for merged list
   
//    leftPos = beg;                               // Initialize left partition position
//    rightPos = mid + 1;                          // Initialize right partition position
   
//    // Add smallest element from left or right partition to merged list
//    while (leftPos <= mid && rightPos <= end) {
//       if (list[leftPos] < list[rightPos]) {
//          mergedNumbers[mergePos] = list[leftPos];
//          ++leftPos;
//       }
//       else {
//          mergedNumbers[mergePos] = list[rightPos];
//          ++rightPos;
         
//       }
//       ++mergePos;
//    }
   
//    // If left partition is not empty, add remaining elements to merged numbers
//    while (leftPos <= mid) {
//       mergedNumbers[mergePos] = list[leftPos];
//       ++leftPos;
//       ++mergePos;
//    }
   
//    // If right partition is not empty, add remaining elements to merged numbers
//    while (rightPos <= end) {
//       mergedNumbers[mergePos] = list[rightPos];
//       ++rightPos;
//       ++mergePos;
//    }
   
//    // Copy merge number back to list
//    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
//       list[beg + mergePos] = mergedNumbers[mergePos];
//    }
   
//    delete [] mergedNumbers;
// }
// #include "Character.h"
// #include <string>

