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
    void inorder(TreeNode *root, vector<int> &sorted)
    {
        if (root == nullptr)
        {
            return;
        }

        inorder(root->left, sorted);
        sorted.push_back(root->val);
        inorder(root->right, sorted);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> sorted;
        inorder(root, sorted);

        int i = 0, j = sorted.size() - 1;
        while (i < j)
        {
            int sum = sorted[i] + sorted[j];

            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        return false;
    }
};

// Inorder + Two Pointers
// TC = O(n)
// SC = O(n)