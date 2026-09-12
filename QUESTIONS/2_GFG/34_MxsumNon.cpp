/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution
{
    pair<int, int> solve(Node *root)
    {
        if (root == nullptr) // Base Case
        {
            return {0, 0};
        }

        pair<int, int> lefT = solve(root->left);  // left Sub-tree
        pair<int, int> rigT = solve(root->right); // right Sub-tree

        pair<int, int> ans;

        ans.first = root->data + lefT.second + rigT.second;                       // sum included this node
        ans.second = max(lefT.first, lefT.second) + max(rigT.first, rigT.second); // sum excluded this node

        return ans;
    }

public:
    int getMaxSum(Node *root)
    {
        // code here
        pair<int, int> ans = solve(root);

        return max(ans.first, ans.second);
    }
};

// Pattern: Tree DP (Take / Not Take)
// TC = O(n)
// SC = O(h) = O(n)

// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1