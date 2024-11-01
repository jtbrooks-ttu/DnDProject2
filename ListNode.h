/*
	Title:   ListNode.h
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/14/24
	Purpose: List Node structure used to traverse Linked List.
*/
#ifndef LISTNODE_HPP
#define LISTNODE_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

template <typename T>
struct ListNode
{
    T value;            // held value
    ListNode *next;     // pointer to next node
    ListNode *previous; // pointer to previous node
};

#endif