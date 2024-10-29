#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>

using namespace std;

class Character{
private:
    string name;
    string charClass;
    string race;
public:
    string getName(){
        return name;
    }
    string getClass(){
        return charClass;
    }
    string getRace(){
        return race;
    }
    void setName(string name){
        this->name = name;
    }
    void setClass(string charClass){
        this->charClass = charClass;
    }
    void setRace(string race){
        this->race = race;
    }
    friend ostream& operator<<(ostream& os, Character& characterList) { 
    os << "Character: " << characterList.name << endl;
    os << "Class: "  << characterList.charClass << endl;
    os << "Race: " << characterList.race << endl;
    return os;
    }
    friend istream& operator>>(istream& is, Character& characterList) { 
    cout << "Character: ";
    getline(is, characterList.name);
    cout << "Class: ";
    getline(is, characterList.charClass);
    cout << "Race: ";
    getline(is, characterList.race);
    return is;
    }
    
};

void printMenu();
int validateInt(int, int, int);
void loadCharacters(string, LinkedList<Character> *);
void printMenu()
{
    cout << "1. Next Character" << endl;
    cout << "2. Previous Character" << endl;
    cout << "3. Add Character" << endl;
    cout << "4. Delete Current Character" << endl;
    cout << "5. Display full list" << endl;
    cout << "6. Exit Program" << endl;
}
/*
    Title: validateInt
    Author: J.T. Brooks
    Date: 9/26/24
    Purpose: Validate user inputted intigers
*/
int validateInt(int choice, int low, int high)
{
    while (!(cin >> choice) || (choice < low || choice > high))
    { // if cin fails, the data type was incorrect, otherwise, the # was out of range
        cin.clear();
        cin.ignore(10000, '\n');
        if (choice > high || choice < low)
            cout << "Number value out of range. Try again: ";
        else
            cout << "Incorrect data type. Try again: ";
    }
    return choice;
}
/*
    Title: loadCharacters
    Author: J.T. Brooks
    Date: 10/7/24
    Purpose: Load list of Characters through file input
*/
void loadCharacters(string fileName, LinkedList<Character> *list)
{
    ifstream infile;
    infile.open(fileName);
    string str;
    Character *ptr;
    while (getline(infile, str, '#'))
    {
        ptr = new Character;
        ptr->setName(str);
        getline(infile, str, '#');
        ptr->setClass(str);
        getline(infile, str, '#');
        ptr->setRace(str);
        list->appendNode(*ptr);
    }
}
#endif