#include <iostream>

struct BinarySearchTreeNode
{
    int data;
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;
};

/**************************Find a node in a tree *****************************/

/*********************** h is a heigth of a tree ******************************/
// Time Complexity :  O(h), Space Complexity : O(n)
BinarySearchTreeNode *Find(BinarySearchTreeNode *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (data < root->data)
    {
        return Find(root->left, data);
    }
    else
    {
        return Find(root->right, data);
    }

    return root;
}

// Time Complexity :  O(n), Space Complexity : O(1)
BinarySearchTreeNode *FindNonRecursive(BinarySearchTreeNode *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    while (root)
    {
        if (data == root->data)
        {
            return root;
        }
        else if (data > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return nullptr;
}

/**********************Finding a minimum node of a tree**************/

// O(n) , O(n)
BinarySearchTreeNode *FindMin(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root->left == nullptr)
    {
        return root;
    }
    else
    {
        return FindMin(root->left);
    }
}

BinarySearchTreeNode *FindMax(BinarySearchTreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    else if (root->right == nullptr)
    {
        return root;
    }
    else
    {
        return FindMin(root->right);
    }
}

// O(h)
void *Insert(BinarySearchTreeNode **root, int data)
{
    BinarySearchTreeNode *newNode;

    if (*root == nullptr)
    {
        newNode = new BinarySearchTreeNode();
        newNode->data = data;
        newNode->right = newNode->right = nullptr;
    }
    else
    {
        if (data > (*root)->data)
        {
            Insert(&((*root)->right), data);
        }
        if (data < (*root)->data)
        {
            Insert(&((*root)->left), data);
        }
    }
}


// O(n) , space Complexity : O(n)
BinarySearchTreeNode *Delete(BinarySearchTreeNode *root, int data)
{
    BinarySearchTreeNode *temp;

    if (root == nullptr)
        throw "ELement not there in tree";
    else if (data < root->data)
    {
        root->left = Delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = Delete(root->right, data);
    }
    else
    {
        // Found element
        if (root->left && root->right)
        {
            temp = FindMax(root->left);
            root->data = temp->data;
            temp->left = Delete(root->left, data);
        }
        else
        {
            /*One Child*/
            temp = root;
            if (root->left == nullptr)
                root = root->right;

            if (root->right == nullptr)
                root = root->left;

            delete (temp);
        }
    }

    return root;
}

int prev = INT16_MIN;
int isBst(BinarySearchTreeNode *root, int *prev)
{
    if (!root)
        return 1;

    if (!isBst(root->left, prev))
        ;
    return 0;

    if (root->data < *prev)
        return 0;

    *prev = root->data;

    return isBst(root->right, prev);
}



