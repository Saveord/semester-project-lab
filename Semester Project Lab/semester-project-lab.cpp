/*
Alexa Wu

Lab: Semester Project Lab

4/24/2025

Windows 11 Home, 24H2, ISO C++14 Standard

Description: This program solves the problem of finding an item in storage 
and allowing the user to edit or delete the item.
*/

#include "BinarySearchTree.h"
#include "Node.h"
#include <iostream>
#include <conio.h> 
using namespace std;

int main()
{
    //add staring binary tree of items
    BinarySearchTree tree;
    tree.Insert("apple", 3, .5);
    tree.Insert("banana", 1, 1.25);
    tree.Insert("milk", 10, 5);
    tree.Insert("watermelon", 20, 5.37);
    tree.Insert("pizza", 6, 7.99);
    tree.Insert("zucchini", 15, 4.32);

    //asks user if they want to either: 
    //find an item, edit an item's quanity and price, delete item, or quit
    int userInput = 0;
    string item;

    while (true)
    { 
        cout << "Type 1 to find an item | Type 2 to edit an item's quanity/price | Type 3 to delete an item | Type 4 to quit" << endl;
        cout << "Type Here: ";
        cin >> userInput;

        if (userInput == 1) //find item
        {
            //asks user to type what item to find
            cout << "Type item name to find: ";
            cin >> item;

            //search for item in binary tree 
            //and print out its quanity and price
            if (tree.Search(item) != nullptr)
            {
                Node* node = tree.Search(item);
                cout << node->itemName << " | quantity: "
                    << node->quantity << " | price | $" << node->price << endl;
            }
            else
            {
                cout << "Item not found!" << endl;
            }

            //clear screen after user presses a key
            cout << "Press any key to continue...";
            int ch = _getch();
            cout << "\033[2J\033[1;1H";
        }
        else if (userInput == 2) //edit item
        {
            int quantity;
            double price;
            cout << "Type item name to edit: ";
            cin >> item;
            cout << "Type new quanity of " << item << ": ";
            cin >> quantity;
            cout << "Type new price of " << item << ": ";
            cin >> price;
            tree.Edit(item, quantity, price);

            //clear screen after user presses a key
            cout << "Press any key to continue...";
            int ch = _getch();
            cout << "\033[2J\033[1;1H";
        }
        else if (userInput == 3) //delete item
        {
            cout << "Type item name to delete: ";
            cin >> item;
            tree.Remove(item);

            //clear screen after user presses a key
            cout << "Press any key to continue...";
            int ch = _getch();
            cout << "\033[2J\033[1;1H";
        }
    }
}

