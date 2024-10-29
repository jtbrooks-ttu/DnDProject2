
/*
	Title:	 LinkedList.h
	Date:	 2-8-2019
	Author:	 J.T. Brooks, Carson Alfaro
	Purpose: Doubly linked list for circular character display.
*/
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "ListNode.h"
#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
private:
	ListNode<T> *head; 
	ListNode<T> *tail;
public:
	
	// Constructor
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}

	// Destructor (similar to a typical RemoveAll function)
	~LinkedList();

	// Linked list operations
	bool isEmpty();
	int getLength();
	void mergeSort(int);
	// void merge(int*, int, int, int);
	T getNodeValue(int);
	int appendNode(T);
	void insertNode(int, T);
	void deleteNode(ListNode<T>*);
	ListNode<T>* begin();
	ListNode<T>* end();
	friend ostream& operator<<(ostream& os, LinkedList<T>& list) { 
		
		ListNode<T> *nodePtr;
		nodePtr = list.begin();

		while (nodePtr)
		{
			os << nodePtr->value << endl;
			nodePtr = nodePtr->next;
		}
    	
		return os;
	}
};

#include "LinkedList.tpp"

#endif