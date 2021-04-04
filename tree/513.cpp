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


// Solution using BFS levelOrder
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> Q;
        TreeNode *temp;
        int res;

        Q.push(root);

        while (!Q.empty())
        {
            if (Q.size() == 1)
            {
                res = Q.front()->val;
            }
            
            temp = Q.front();
            Q.pop();

            cout << temp->val << " ";

            if (temp->right)
            {
                Q.push(temp->right);
            }

            if (temp->left)
            {
                Q.push(temp->left);
            }

          
        }

        return res;
    }
};