
class Solution
{
public:
    stack<TreeNode *> stack1;
    stack<TreeNode *> stack2;

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        Preoder(root1, &stack1);
        Preoder(root2, &stack2);

        if (stack1.size() == stack2.size())
        {
            while (!stack1.empty())
            {
                if (stack1.top()->val != stack2.top()->val)
                {
                    return false;
                }
                
                std::cout << stack1.top()->val; 
                stack1.pop();
                stack2.pop();
            }
        }
        else
        {
            return false;
        }

        return true;
    }

    void Preoder(TreeNode *root, stack<TreeNode *> *stk)
    {
        if (root)
        {
            if (root != nullptr && root->left == nullptr && root->right == nullptr)
                stk->push(root);

            Preoder(root->left, stk);
            Preoder(root->right, stk);
        }
    }
};