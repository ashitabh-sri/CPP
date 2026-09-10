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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (root == nullptr)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);
        bool LtoR = true;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> ans(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *frnt = q.front();
                q.pop();

                int idx = LtoR ? i : n - 1 - i;
                ans[idx] = frnt->val;

                if (frnt->left)
                {
                    q.push(frnt->left);
                }
                if (frnt->right)
                {
                    q.push(frnt->right);
                }
            }

            res.push_back(ans);
            LtoR = !LtoR;
        }

        return res;
    }
};

// TC = O(n), n = no. of nodes
// SC = O(w) = O(n), w = width of tree