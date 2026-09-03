/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

// Class Solution
class Solution
{
    void iot(Node *root, int &cnt)
    {
        if (root == nullptr)
        {
            return;
        }

        iot(root->left, cnt);

        if (root->left == nullptr && root->right == nullptr)
        {
            cnt++;
        }

        iot(root->right, cnt);
    }

public:
    // Function to count the number of leaf nodes in a binary tree.
    int countLeaves(Node *root)
    {
        // write code here
        int cnt = 0;

        iot(root, cnt);

        return cnt;
    }
};

// TC = O(n), n = no. of nodes
// SC = O(h), h = height of tree / no. of levels

// https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1