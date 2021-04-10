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
    int diameter;
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0;
        maxPath(root);
        return diameter;
    }
    
    int maxPath(TreeNode* root)
    {
         int leftHeight;
         int rightHeight;

         if (root == nullptr)
            return 0;
        
        leftHeight = maxPath(root->left);
        rightHeight = maxPath(root->right);

        diameter = max(diameter, leftHeight + rightHeight);
    
    
        return max(leftHeight,rightHeight)+1;
        
               
    }
};