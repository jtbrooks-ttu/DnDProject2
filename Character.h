/*
	Title:   Character.h
	Author:  J.T. Brooks, Carson Alfaro, Max Beaty
	Date:    10/14/24
	Purpose: Data class. Contains members name, class, and race for user to input.
*/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>

using namespace std;

class Character{ //Data class
private:
    string name;
    string charClass;
    string race;
public:
    //getter and setter functions
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
    //overloaded output operators
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
    bool operator>(const Character& otherChar) { // compares by Character name
        int num;
        num = this->name.compare(otherChar.name);
        return (num > 0);
    }
    bool operator<(const Character& otherChar) { // compares by Character name
        int num;
        num = this->name.compare(otherChar.name);
        return (num < 0);
    }
    bool operator==(const Character& otherChar){ // compares by Character name
        return(!(this->name.compare(otherChar.name)));
    }
    
};

void printMenu();
int validateInt(int, int, int);
void loadCharacters(string, LinkedList<Character> *);
/*
    Title: printMenu
    Author: J.T. Brooks
    Date: 11/01/24
    Purpose: Prints menu to screen
*/
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
int validateInt(int choice, int low, int high) //validates user inputted inetgers
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
#endif