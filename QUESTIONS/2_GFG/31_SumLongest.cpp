/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution
{
    void solve(Node *root, int len, int &mxlen, int sum, int &mxsum)
    {
        if (root == nullptr)
        {
            if (len > mxlen)
            {
                mxlen = len; // update mxlen
                mxsum = sum; // we want sum of longest path
            }
            else if (len == mxlen)
            {
                mxsum = max(sum, mxsum);
            }

            return;
        }

        sum += root->data;

        solve(root->left, len + 1, mxlen, sum, mxsum);
        solve(root->right, len + 1, mxlen, sum, mxsum);
    }

public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        // code here
        int mxlen = 0;
        int mxsum = 0;

        solve(root, 0, mxlen, 0, mxsum);

        return mxsum;
    }
};

// TC = O(n)
// SC = O(n)

// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1