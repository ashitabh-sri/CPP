/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution
{
    void solve(Node *root, vector<int> &ans, int lvl)
    {
        if (root == nullptr)
        {
            return;
        }

        if (lvl == ans.size())
        {
            ans.push_back(root->data);
        }

        solve(root->right, ans, lvl + 1);
        solve(root->left, ans, lvl + 1);
    }

public:
    vector<int> rightView(Node *root)
    {
        // code here
        vector<int> ans;

        solve(root, ans, 0);

        return ans;
    }
};

// TC = O(n)
// SC = O(n)

// https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1