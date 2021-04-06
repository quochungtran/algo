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
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        
        if (root == nullptr || !constainsOne(root))
            return nullptr;
        
            return root;
    }
    
    bool constainsOne(TreeNode* node)
    {
        if (node == nullptr)
            return false;
        
        bool a1 = constainsOne(node->left);
        bool a2 = constainsOne(node->right);
        
        if(!a1) 
            node->left = nullptr;
        
        if (!a2)
            node->right = nullptr;
        
        return node->val == 1 || a1 || a2;
    }
};