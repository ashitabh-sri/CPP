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
    unordered_map<int, int> mp;
    int preId = 0;
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int beg, int end)
    {
        if (beg > end) // leaf node : no elements for subtree in inorder
        {
            return nullptr;
        }

        int val = preorder[preId++];        // next root node from preorder
        TreeNode *root = new TreeNode(val); // create the node

        int pos = mp[val]; // index of this node in inorder

        root->left = solve(preorder, inorder, beg, pos - 1);
        root->right = solve(preorder, inorder, pos + 1, end);

        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();
        for (int i = 0; i < n; i++) // pre-calculate inorder element's index
        {
            mp[inorder[i]] = i;
        }

        return solve(preorder, inorder, 0, n - 1);
    }
};

// TC = O(n) average
// SC = O(n)