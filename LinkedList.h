/*
	Title:   LinkedList.h
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/14/24
	Purpose: Header file containing function definitions and template class
	Linked List.
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
	
	LinkedList() // constructor
	{
		head = NULL;
		tail = NULL;
	}

	~LinkedList(); // destructor

	bool isEmpty();
	ListNode<T>* split(ListNode<T>*);
	ListNode<T>* merge(ListNode<T>*, ListNode<T>*, const int sortDirection);
	ListNode<T>* MergeSort(ListNode<T>*, const int sortDirection);
	T getNode(int);
	int appendNode(T);
	void deleteNode(ListNode<T>*);
	ListNode<T>* begin();
	ListNode<T>* end();
	void setEnd(ListNode<T>*);
	void setHead(ListNode<T>*);
	friend ostream& operator<<(ostream& os, LinkedList<T>& list) { 
		
		ListNode<T> *nodePtr;
		nodePtr = list.end();
		nodePtr->next = NULL;
		nodePtr = list.begin();
		
		while(nodePtr){ // iterates through list and prints Character
			os << nodePtr->value << endl;
			nodePtr = nodePtr->next;
		}
		nodePtr = list.end();
		nodePtr->next = list.begin();
    	
		return os;
	}
};

#include "LinkedList.tpp" // LinkedList template file

#endif