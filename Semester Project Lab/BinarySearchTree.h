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
		root = nullptr; //initalize root as null
	}
    //insert fuction to add new items to binary tree
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
                //compares if item name is alphabetically less than current node's item name
                if (item->itemName.compare(currentNode->itemName) < 0) 
                {
                    //if item is less than current node then 
                    //assign it to the current node's left child
                    if (currentNode->left == nullptr) 
                    {
                        currentNode->left = item;
                        currentNode = nullptr;
                    }
                    //if current node already has a left child then 
                    //while loop repeats again w/ current node's left child
                    else 
                    {
                        currentNode = currentNode->left;
                    }
                }
                //if item is greater than current node then 
                //assign it to the current node's right child
                else 
                {
                    if (currentNode->right == nullptr) 
                    {
                        currentNode->right = item;
                        currentNode = nullptr;
                    }
                    //if current node already has a right child then
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
            // return the node if the item name matches
            if (currentNode->itemName.compare(desiredItem) == 0)
            {
                return currentNode;
            }
            // navigate to the left if the search item name is 
            // less than the current node's item name
            else if (desiredItem.compare(currentNode->itemName) < 0) 
            {
                currentNode = currentNode->left;
            }

            // navigate to the right if the search item name is 
            // greater than the current node's item name.
            else 
            {
                currentNode = currentNode->right;
            }
        }
        return nullptr; //the item was not found in the tree
    }//end of Search function

    //Remove function to remove an item from binary tree
    bool Remove(string itemName) 
    {
        //initalize parent pointer and current node
        Node* parent = nullptr;
        Node* currentNode = root;

        // search for the item to be removed
        while (currentNode) 
        {
            //if current node has matching item name
            if (currentNode->itemName.compare(itemName) == 0)
            {
                //if current node is a leaf node
                if (currentNode->left == nullptr && currentNode->right == nullptr) 
                { 
                    //if current node is root with no children 
                    // then remove node if true
                    if (parent == nullptr)
                    { 
                        root = nullptr;
                    }
                    //checks if current node is a left/right child leaf node
                    //then set parent's left/right child pointer to null
                    else if (parent->left == currentNode) 
                    {
                        parent->left = nullptr;
                    } 
                    else 
                    {
                        parent->right = nullptr;
                    }
                    delete currentNode; //deletes item from binary tree
                    cout << "Item sucessfully deleted!" << endl;
                    return true;
                }
                //if current node has a left child
                else if (currentNode->left && currentNode->right == nullptr) 
                {
                    if (parent == nullptr) //node is root
                    {
                        root = currentNode->left; //set root as current node's left child
                    }
                    //if current node is not a root then sets
                    //parent's left/right child pointer to current node's left child
                    else if (parent->left == currentNode) 
                    {
                        parent->left = currentNode->left;
                    }
                    else 
                    {
                        parent->right = currentNode->left;
                    }
                    delete currentNode; //deletes item from binary tree
                    cout << "Item sucessfully deleted!" << endl;
                    return true;
                }
                //if current node has a right child
                else if (currentNode->left == nullptr && currentNode->right) 
                {
                    if (parent == nullptr) //node is root
                    { 
                        root = currentNode->right;
                    }
                    //if current node is not a root then sets
                    //parent's left/right child pointer to current node's right child
                    else if (parent->left == currentNode) 
                    {
                        parent->left = currentNode->right;
                    }
                    else {
                        parent->right = currentNode->right;
                    }
                    delete currentNode; //deletes item from binary tree
                    cout << "Item sucessfully deleted!" << endl;
                    return true;
                }
                //if current node has two children
                else 
                { 
                    //find successor (leftmost child of right subtree)
                    Node* successor = currentNode->right;
                    while (successor->left) {
                        successor = successor->left;
                    }
                    currentNode->itemName = successor->itemName; //copy successor's item name to current node
                    parent = currentNode;

                    //reassigned current node and item name so that loop continues with new item name
                    currentNode = currentNode->right;
                    itemName = successor->itemName;
                }
            } 
            //if current node does not equal item name
            else if (currentNode->itemName.compare(itemName) > 0) //search right
            { 
                parent = currentNode;
                currentNode = currentNode->right;
            }
            else //search left
            {
                parent = currentNode;
                currentNode = currentNode->left;
            }
        }
        cout << "Item not found!" << endl; //node not found
        return false;
    } //end of Remove function

    //Edit function to change item quanity and price
    bool Edit(string itemName, int quantity, double price)
    {
        Node* item = Search(itemName); //searches for item first
        if (item != nullptr)
        {
            //sets new quantity and price for item
            item->quantity = quantity;
            item->price = price;
            cout << "Edit sucessful!" << endl;
            return true;
        }
        cout << "Item not found!" << endl;
        return false;
    }
};
#endif