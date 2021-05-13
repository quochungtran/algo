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
    
    map<int,int> orderList;
    int id = 0;
  
    TreeNode* convertBST(TreeNode* root) 
    {
        inorder(root, orderList); 
        
        for (auto const& x : orderList)
        {
            std::cout << x.first  // string (key)
              << ':' 
              << x.second // string's value 
              << std::endl;
        }
        
        
        return nullptr;
    }
    
    int sum(int value,map<int,int>& map)
    {
        int S = 0;
        for (int i = map[value] ; i < map.size() ; i++)
        {
            S += 
        }
    }
    
    void inorder(TreeNode * tree, map<int,int>& map)
    {
        if (tree)
        {
            inorder(tree->left, map);
            map.insert(pair<int,int>(tree->val, id));
            id++;
            inorder(tree->right,map);
        }
    }
};