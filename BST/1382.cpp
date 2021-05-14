class Solution
{
public:

    // Construct a new balanced tree from the sorted array recursively.
    TreeNode *build_height_balanced_treefrom_array(vector<int> &a, int s, int e)
    {
        if (s > e)
        {
            return nullptr;
        }

        int mid = (s + e) / 2;

        TreeNode *root = new TreeNode(a[mid]);
        root->left     = build_height_balanced_treefrom_array(a, s, mid - 1);
        root->right    = build_height_balanced_treefrom_array(a, mid + 1, e);
        return root;
    }

    // Convert the tree to a sorted array using an in-order traversal.
    void add_invector(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }
        add_invector(root->left, arr);
        arr.push_back(root->val);
        add_invector(root->right, arr);
        return;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> arr;
        add_invector(root, arr);
    
        return build_height_balanced_treefrom_array(arr, 0, arr.size() - 1);
    }
};