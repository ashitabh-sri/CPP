/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
    int minValue(Node *root)
    {
        // code here
        Node *tem = root;
        while (tem->left)
        {
            tem = tem->left;
        }

        return tem->data;
    }
};

// BST Search
// TC = O(h)
// SC = O(1)

// https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1