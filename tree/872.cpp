
class Solution
{
public:
   

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        stack<int > stack1;
        stack<int > stack2;
        Preoder(root1, &stack1);
        Preoder(root2, &stack2);
        
        return stack1 == stack2;
    }

    void Preoder(TreeNode *root, stack<int > *stk)
    {
        if (root == nullptr)
            return ;
        if (root != nullptr)
        {
            if (root != nullptr && root->left == nullptr && root->right == nullptr)
                stk->push(root->val);

            Preoder(root->left, stk);
            Preoder(root->right, stk);
        }
    }
};