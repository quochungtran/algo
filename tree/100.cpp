/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    void displayVector(vector<int> vec)
    {
        for (int i : vec)
        {
            std::cout << i << " ";
        }

        std::cout << "\n";
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        vector<int> valNodesp;
        vector<int> valNodesq;

        PreOrder(p, &valNodesp);
        PreOrder(q, &valNodesq);

        displayVector(valNodesp);
        displayVector(valNodesq);

        return valNodesp == valNodesq;
    }

    void PreOrder(TreeNode *root, vector<int> *valNodes)
    {
        if (root)
        {
            valNodes->push_back(root->val);
            PreOrder(root->left, valNodes);
            PreOrder(root->right, valNodes);
        }
        else
            valNodes->push_back(10000);
    }
};