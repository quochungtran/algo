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
    int id = 0;
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode> stk;

        while (true)
        {
            while (root != nullptr)
            {
                stk.push_back(root);
                root = root->left;
            }

            // handle the node
            root = stk.pop();

            k -= 1;

            if (--k == 0)
                return root->val;

            root = root->right;
        }
    }
};