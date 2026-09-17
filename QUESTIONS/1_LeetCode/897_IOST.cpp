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
    void inorder(TreeNode *root, vector<TreeNode *> &iot)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left, iot);
        iot.push_back(root);
        inorder(root->right, iot);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<TreeNode *> iot;
        inorder(root, iot);
        int n = iot.size();

        for (int i = 0; i < n - 1; i++)
        {
            iot[i]->left = nullptr;
            iot[i]->right = iot[i + 1];
        }
        iot[n - 1]->left = iot[n - 1]->right = nullptr;

        return iot[0]; // new root node
    }
};

// Inorder Traversal in BST
// TC = O(n)
// SC = O(n)