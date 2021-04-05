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
  
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> Queue;

        Queue.push(root);
        

        while (!Queue.empty())
        {
            int count = Queue.size();
            
            for (int i = 0 ; i< count ; i++)
            {
                TreeNode * tempNode = Queue.front();
                Queue.pop();
                
                if (i == count-1)
                {
                    if (tempNode)
                        res.push_back(tempNode->val);
                }
                if (tempNode != nullptr && tempNode->left)
                {
                    Queue.push(tempNode->left);
                }
                 
                if (tempNode != nullptr && tempNode->right)
                {
                    Queue.push(tempNode->right);
                }
                   
            }
            
             
        }
        
        res.shrink_to_fit(); 
        return res;       
    }
};