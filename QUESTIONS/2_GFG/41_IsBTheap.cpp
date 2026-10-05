// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution
{
    int countNodes(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    bool isCBT(Node *root, int i, int n)
    {
        if (root == nullptr)
        { // base case
            return true;
        }

        if (i >= n)
        {                 // invalid node for CBT
            return false; // nodes are filled from left in CBT
        }
        else
        {
            // 0-based indexing
            bool left = isCBT(root->left, 2 * i + 1, n);   // left child
            bool right = isCBT(root->right, 2 * i + 2, n); // right child

            return (left && right);
        }
    }
    bool isMax(Node *root)
    {
        if (root == nullptr)
        { // base case
            return true;
        }

        if (root->left == nullptr && root->right == nullptr)
        { // leaf node
            return true;
        }

        if (root->right == nullptr)
        { // if only have left child
            return root->data >= root->left->data;
        }
        else
        {
            return (root->data >= root->left->data && root->data >= root->right->data && isMax(root->left) && isMax(root->right));
        }
    }

public:
    bool isHeap(Node *tree)
    {
        // code here
        int i = 0;                // index of node
        int n = countNodes(tree); // total nodes

        return isCBT(tree, i, n) && isMax(tree);
    }
};

// Tree + Heap
// TC = O(n)
// SC = O(h), Recursive Stack