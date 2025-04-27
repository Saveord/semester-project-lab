#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Node.h"
using namespace std;

class BinarySearchTree
{
private:

	Node* root;

public:

	BinarySearchTree()
	{
		root = nullptr;
	}
    //Insert fuction to add new items to binary tree
	void Insert(string itemName, int quantity, double price)
	{
        Node* item = new Node(itemName, quantity, price); //creates new node for item

		if (root == nullptr) 
		{
			root = item;
		}
        else
        {
            Node* currentNode = root;

            while (currentNode) 
            {
                //Compares if item name is alphabetically less than current node's item name
                if (item->itemName.compare(currentNode->itemName) < 0) 
                {
                    //If item is less than current node then 
                    //assign it to the current node's left child
                    if (currentNode->left == nullptr) 
                    {
                        currentNode->left = item;
                        currentNode = nullptr;
                    }
                    //If current node already has a left child then 
                    //while loop repeats again w/ current node's left child
                    else 
                    {
                        currentNode = currentNode->left;
                    }
                }
                //If item is greater than current node then 
                //assign it to the current node's right child
                else 
                {
                    if (currentNode->right == nullptr) 
                    {
                        currentNode->right = item;
                        currentNode = nullptr;
                    }
                    //If current node already has a right child then
                    //while loop repeats again w/ current node's right child
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
	} //end of Insert function

    //Search function to search for an item in the binary tree
    Node* Search(string desiredItem) 
    {
        Node* currentNode = root;

        while (currentNode) 
        {
            // Return the node if the item name matches
            if (currentNode->itemName.compare(desiredItem) == 0)
            {
                cout << currentNode->itemName << ": quantity " 
                    << currentNode->quantity <<", price: $" << currentNode->price << endl;
                return currentNode;
            }
            // Navigate to the left if the search item name is 
            // less than the current node's item name
            else if (desiredItem.compare(currentNode->itemName) < 0) 
            {
                currentNode = currentNode->left;
            }

            // Navigate to the right if the search item name is 
            // greater than the current node's item name.
            else 
            {
                currentNode = currentNode->right;
            }
        }
        cout << "Item not found!" << endl; // The item was not found in the tree
    }//end of Search function
};
#endif