#include <iostream>

struct AVLTreeNode
{
    int height;
    int data;
    AVLTreeNode *left;
    AVLTreeNode *right;
};

// Finding the Height of an AVL tree


// Time Complexity : O(1)
int Height(AVLTreeNode *root)
{
    if (!root)
    {
        return -1;
    }
    else 
        return root->height;
} 




