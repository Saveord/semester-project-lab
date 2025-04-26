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
    //fuction to add new items to binary tree
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
                if (item->itemName < currentNode->itemName) 
                {
                    //If item is less than current node then assign it to the current node's left child
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
                //If item is greater than current node then assign it to the current node's right child
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
};
#endif