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
    int pstId;
    TreeNode *solve(vector<int> &postorder, vector<int> &inorder, int beg, int end)
    {
        if (beg > end) // leaf node : no elements for subtree in inorder
        {
            return nullptr;
        }

        int val = postorder[pstId--];       // next root node from preorder
        TreeNode *root = new TreeNode(val); // create the node

        int pos = mp[val]; // index of this node in inorder

        root->right = solve(postorder, inorder, pos + 1, end); // traversing post-order from right to left
        root->left = solve(postorder, inorder, beg, pos - 1);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        pstId = n - 1;              // same size for inorder & postorder
        for (int i = 0; i < n; i++) // pre-calculate inorder element's index
        {
            mp[inorder[i]] = i;
        }

        return solve(postorder, inorder, 0, n - 1);
    }
};

// TC = O(n) average
// SC = O(n)