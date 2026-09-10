/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution
{
    void travLeft(Node *root, vector<int> &ans)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return;
        }

        ans.push_back(root->data);

        if (root->left)
        {
            travLeft(root->left, ans);
        }
        else
        {
            travLeft(root->right, ans);
        }
    }
    void travLeaf(Node *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(root->data);
            return;
        }

        travLeaf(root->left, ans);
        travLeaf(root->right, ans);
    }
    void travRight(Node *root, vector<int> &ans)
    {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        {
            return;
        }

        if (root->right)
        {
            travRight(root->right, ans);
        }
        else
        {
            travRight(root->left, ans);
        }

        ans.push_back(root->data);
    }

public:
    vector<int> boundaryTraversal(Node *root)
    {
        // code here
        vector<int> ans;
        ans.push_back(root->data); // insert root at first

        // traverse left bounday : root to leftmost non-leaf node
        travLeft(root->left, ans);

        // traverse leaf nodes : leaf nodes
        travLeaf(root->left, ans);  // left subtree leaf nodes
        travLeaf(root->right, ans); // right subtree leaf nodes

        // traverse right bounday : rightmost non-leaf node to pre root node
        travRight(root->right, ans);

        return ans;
    }
};

// TC = O(n)
// SC = O(n)

// https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1