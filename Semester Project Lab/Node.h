#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Node 
{
public:

    string itemName;
    int quantity;
    double price;
    Node* left;
    Node* right;

    Node(string itemName, int quantity, double price) 
    {
        this->itemName = itemName;
        this->quantity = quantity;
        this->price = price;
        left = nullptr;
        right = nullptr;
    }
};
#endif