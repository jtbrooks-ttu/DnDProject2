
#include "LinkedList.h"
#include "Character.h"
#include <string>

using namespace std;

int main()
{
	int counter = 0;
	ListNode<Character>* countPtr;
	Character newChar;
	LinkedList<Character> list;
	ListNode<Character> *it;
	ListNode<Character> *end;
	if (!list.isEmpty())
	{
		it = list.begin();
		end = list.end();
	}

	cout << string(80, '*') << "\n\t\tWELCOME TO DND CHARACTER SELECTION\n"
		 << string(80, '*') << endl;

	// input integer for our switch statement
	int choice = 0;

	loadCharacters("characters.txt", &list);

	while (choice != 6)
	{
		if (list.isEmpty())
			cout << endl
				 << "No characters found..." << endl
				 << endl;
		else
			cout << endl
				 << it->value << endl;
		printMenu();
		cout << "Choice: ";
		choice = validateInt(choice, 1, 5);
		switch (choice)
		{
		case 1:
			if (it == end)
				it = list.begin();
			else
				it = it->next;
			break;
		case 2:

			if (it == list.begin())
				it = end;
			else
				it = it->previous;
			break;
		case 3:
			cout << endl;
            cin.ignore();
			cin >> newChar;
			if (list.appendNode(newChar) == 1)
			{
				it = list.begin();
			}
			else
			{
				it = it->next;
			}
			end = list.end();
			break;
		case 4:
			list.deleteNode(it);
			it = list.begin();
			end = list.end();
			break;
		case 5:
			countPtr = list.begin();
			if(!list.isEmpty()){
				while(countPtr->next != NULL){
					countPtr = countPtr->next;
					counter++;
				}
			}
			list.mergeSort(counter);
            cout << endl;
			cout << list;
			break;
		case 6:
			break;
		default:
			cout << "You shouldn't be here" << endl;
			break;
		}
	}
	return 0;
}