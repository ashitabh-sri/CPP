/* Structure of binary tree node
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
public:
    vector<int> diagonal(Node *root)
    {
        // code here
        vector<int> ans;

        queue<Node *> q; // track the order
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();

            while (node) // until nullptr
            {
                ans.push_back(node->data);

                if (node->left)
                {
                    q.push(node->left); // store left for later
                }

                node = node->right; // keep going right
            }
        }

        return ans;
    }
};

// TC = O(n)
// SC = O(n)

// https://www.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1