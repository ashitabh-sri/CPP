/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution
{
public:
    vector<Node *> findPreSuc(Node *root, int key)
    {
        // code here
        Node *pre = nullptr;
        Node *suc = nullptr;

        Node *cur = root;
        while (cur)
        {
            if (cur->data == key)
            {

                if (cur->left)
                {
                    Node *tem = cur->left; // goes to left subtree
                    while (tem->right)     // finds the rightmost node
                    {
                        tem = tem->right;
                    }
                    pre = tem;
                }

                if (cur->right)
                {
                    Node *tem = cur->right; // goes to right subtree
                    while (tem->left)       // finds the leftmost node
                    {
                        tem = tem->left;
                    }
                    suc = tem;
                }

                break;
            }

            if (cur->data > key)
            {
                suc = cur; // Inorder in BST is..
                cur = cur->left;
            }
            else
            {
                pre = cur; // ..in Sorted order
                cur = cur->right;
            }
        }

        return {pre, suc};
    }
};

// TC = O(h)
// SC = O(1)

// https://www.geeksforgeeks.org/problems/predecessor-and-successor/1