/*
Alexa Wu

Lab: Semester Project Lab

4/24/2025

Windows 11 Home, 24H2, ISO C++14 Standard

Description: This program solves the problem of revtriving the 
quanity and price of an item in a large list.
*/

#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main()
{
    //add staring binary tree of items
    BinarySearchTree tree;
    tree.Insert("apple", 3, .5);
    tree.Insert("banana", 1, 1.25);

    //asks user if they want to either: 
    //find an item, edit an items quanity, or edit an item's price
    int userInput;
    cout << "Type 1 to find an item | Type 2 to edit an item's quanity/price | Type 3 to delete an item" << endl;
    cout << "Type Here: ";
    cin >> userInput;
    if (userInput == 1) //find item
    {
        //asks user to type what item to find
        string item;
        cout << "Input Item Name: ";
        cin >> item;
        //search for item in binary tree 
        //and print out its quanity and price
        tree.Search(item);
    }
    else if (userInput == 2) //edit item
    {

    }
    else //delete item
    {

    }
    //allow adding and deleting quanity of items and editing price.
}

