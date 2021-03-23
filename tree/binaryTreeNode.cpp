#include <iostream>
#include <stack>

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
};

// ******************** traversal tree ********************

// recursive version

void PreOrder(BinaryTreeNode *root)
{
    if (root)
    {
        std::cout << root->data;
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(BinaryTreeNode *root)
{
    if (root)
    {
        PreOrder(root->left);
        std::cout << root->data;
        PreOrder(root->right);
    }
}

void PostOrder(BinaryTreeNode *root)
{
    if (root)
    {
        PreOrder(root->left);
        PreOrder(root->right);
        std::cout << root->data;
    }
}

// non recursive, complexity : O(n)

void PreOrderNonRecursive(BinaryTreeNode *root)
{
    std::stack<BinaryTreeNode *> stack;

    while (1)
    {
        while (root)
        {
            std::cout << root->data;
            stack.push(root);
            root = root->left;
        }

        if (stack.empty())
            break;

        root = stack.top();
        stack.pop();

        root = root->right;
    }
}

void PostNonRecursive(BinaryTreeNode *root)
{
    std::stack<BinaryTreeNode *> stack;

    while (1)
    {
        while (root)
        {
            stack.push(root);
            root = root->left;
        }

        if (stack.empty())
            break;

        root = stack.top();
        stack.pop();

        root = root->right;

        std::cout << root->data;
    }
}

void InOrderNonRecursive(BinaryTreeNode *root)
{
    std::stack<BinaryTreeNode *> stack;
    BinaryTreeNode *previous = nullptr;

    do
    {
        while (root != nullptr)
        {
            stack.push(root);
            root = root->left;
        }

        while (root == nullptr && !stack.empty())
        {
            root = stack.top();
            if (root->right == nullptr || root->right == previous)
            {
                std::cout << root->data;
                stack.pop();
                previous = root;
                root = nullptr;
            }
            else
            {
                root = root->right;
            }
        }

    } while (!stack.empty());
}
