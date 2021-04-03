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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> resultat;
        levelOrdre(root, &resultat);
        return resultat;
    }

    void levelOrdre(TreeNode *root, vector<double> *vec)
    {
        
        queue<TreeNode *> Q;

        if (root == nullptr)
            return;

        Q.push(root);

        while (!Q.empty())
        {
            long int sum = 0;
            int count = 0;
            double mean = 0;
            queue<TreeNode *> Q2; /* Q2 is created for stock nodes of each level*/
            TreeNode *temp;
            
            while (!Q.empty())
            {
                temp = Q.front();
                Q.pop();

                sum += temp->val;
                count++;

                if (temp->left)
                {
                    Q2.push(temp->left);
                }
                if (temp->right)
                {
                    Q2.push(temp->right);
                }
            }

            Q = Q2;
            mean = double(sum) / count;
            vec->push_back(mean);
        }
    }
};