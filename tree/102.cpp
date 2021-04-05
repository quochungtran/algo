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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> Queue;
        TreeNode *tempNode;
        vector<int> row;
        vector<vector<int>> resultat;

        if (root == nullptr)
        {
            return resultat;
        }

        Queue.push(root);

        while (!Queue.empty())
        {
            queue<TreeNode *> tempQueue;
            vector<int> row;
            while (!Queue.empty())
            {
                tempNode = Queue.front();
                Queue.pop();

                row.push_back(tempNode->val);
                // std::cout << tempNode->val << " ";

                if (tempNode->left)
                    tempQueue.push(tempNode->left);

                if (tempNode->right)
                    tempQueue.push(tempNode->right);
            }

            resultat.push_back(row);

            Queue = tempQueue;
        }

        return resultat;
    }
};