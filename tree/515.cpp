
#include <iostream>
#include <queue>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {
        queue<TreeNode *> Q;
        vector<int> res;

        if (root == nullptr)
            return res;

        Q.push(root);

        res.push_back(Max(Q));

        while (!Q.empty())
        {
            queue<TreeNode *> tempQueue;
            TreeNode *tempNode;

            while (!Q.empty())
            {
                tempNode = Q.front();
                Q.pop();

                if (tempNode->left)
                    tempQueue.push(tempNode->left);

                if (tempNode->right)
                    tempQueue.push(tempNode->right);
            }

            if (!tempQueue.empty())
            {
                res.push_back(Max(tempQueue));
            }
            Q = tempQueue;
        }

        return res;
    }

    int Max(queue<TreeNode *> Q1)
    {
        int max = Q1.front()->val;
        int tempVal;
        while (!Q1.empty())
        {
            tempVal = Q1.front()->val;
            Q1.pop();

            if (tempVal >= max)
            {
                max = tempVal;
            }
        }
        return max;
    }
};