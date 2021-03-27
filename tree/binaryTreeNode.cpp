#include <iostream>
#include <stack>
#include <queue>
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
        std::cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(BinaryTreeNode *root)
{
    if (root)
    {
        PreOrder(root->left);
        std::cout << root->data << " ";
        PreOrder(root->right);
    }
}

void PostOrder(BinaryTreeNode *root)
{
    if (root)
    {
        PreOrder(root->left);
        PreOrder(root->right);
        std::cout << root->data << " ";
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

//insert in Binary Tree

void InsertInBinaryTree(BinaryTreeNode **root, int data)
{
    std::queue<BinaryTreeNode *> Q;

    BinaryTreeNode *newNode = new BinaryTreeNode();
    newNode->left = newNode->right = nullptr;
    newNode->data = data;

    BinaryTreeNode *temp;

    if (*root == nullptr)
    {
        *root = newNode;
        return;
    }

    Q.push(*root);

    if (!Q.empty())
    {
        temp = Q.front();

        if (temp->left)
        {
            Q.push(newNode);
        }
        else
        {
            temp->left = newNode;
            return;
        }

        if (temp->right)
        {
            Q.push(newNode);
        }
        else
        {
            temp->right = newNode;
            return;
        }
    }
}

int FindMaxUsingLevelOlder(BinaryTreeNode *root)
{
    int max = INT16_MIN;
    BinaryTreeNode *temps;
    std::queue<BinaryTreeNode *> Q;

    Q.push(temps);

    while (!Q.empty())
    {
        temps = Q.front();
        Q.pop();

        if (max <= temps->data)
            max = temps->data;

        if (temps->left)
        {
            Q.push(temps->left);
        }

        if (temps->right)
        {
            Q.push(temps->right);
        }
    }

    return max;
}

int FindInBinaryTreeUsingRercusion(BinaryTreeNode *root, int item)
{
    int temp;
    if (root == nullptr)
        return 0;

    if (root->data == item)
        return 1;
    else
    {
        temp = FindInBinaryTreeUsingRercusion(root->left, item);
        if (temp != 0)
            return temp;
        else
            return FindInBinaryTreeUsingRercusion(root->right, item);
    }

    return 0;
}

int SizeOfBinaryTree(BinaryTreeNode *root)
{
    if (root == nullptr)
        return 0;
    else
        return (SizeOfBinaryTree(root->left) + 1 + SizeOfBinaryTree(root->right));
}

int heightOfBinaryTree(BinaryTreeNode *root)
{
    int leftHeight;
    int rightHeight;

    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        leftHeight = heightOfBinaryTree(root->left);
        rightHeight = heightOfBinaryTree(root->right);

        if (leftHeight < rightHeight)
            return leftHeight + 1;
        else
            return rightHeight + 1;
    }
}

int main()
{
    BinaryTreeNode *tree = nullptr;
    InsertInBinaryTree(&tree, 1);
    InsertInBinaryTree(&tree, 2);
    InsertInBinaryTree(&tree, 3);


    InOrder(tree);

    return 0;
}