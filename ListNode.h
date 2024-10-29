#ifndef LISTNODE_HPP
#define LISTNODE_HPP
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

template <typename T>
struct ListNode
{
    T value;              // The value in this node
    ListNode *next;     // To point to the next node
    ListNode *previous; // To point to the previous node
};

#endif