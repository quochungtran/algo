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
    int rootToLeft = 0 ;
    
    void preoder(TreeNode* r, int currentNumber)
    {
        if (r != nullptr)
        {
            currentNumber = (currentNumber << 1) | r->val;
            
            if (r->left == nullptr && r->right == nullptr)
            {
                rootToLeft += currentNumber ;
            }
            
            preoder(r->left, currentNumber);
            preoder(r->right, currentNumber);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        
        preoder(root, 0);
        return rootToLeft;
    }
};