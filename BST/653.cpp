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
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> orderlist;
        inorder(root, orderlist);
        int start = 0;
        int end = orderlist.size() - 1;

        while (start < end)
        {
            int sum = orderlist[end] + orderlist[start];
            if (sum < k)
            {
                start++;
            }
            else if (sum > k)
            {
                end--;
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    // inorder traversal to convert a BST to a sorted array
    void inorder(TreeNode *root, vector<int> &list)
    {
        if (root)
        {
            inorder(root->left, list);
            list.push_back(root->val);
            inorder(root->right, list);
        }
    }
};