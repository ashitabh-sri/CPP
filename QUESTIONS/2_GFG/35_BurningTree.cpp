/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution
{
    unordered_map<Node *, Node *> Parent; // tracks parent node, operations O(1) average
    Node *mapping(Node *root, int target) // O(n)
    {
        Node *tnode = nullptr;

        queue<Node *> q;

        q.push(root);
        Parent[root] = nullptr; // root node doesn't have parent

        while (!q.empty())
        {
            Node *tem = q.front();
            q.pop();

            if (tem->data == target) // found target node
            {
                tnode = tem;
            }

            // if child exists, map child to it's parent node
            if (tem->left)
            {
                q.push(tem->left);
                Parent[tem->left] = tem;
            }
            if (tem->right)
            {
                q.push(tem->right);
                Parent[tem->right] = tem;
            }
        }

        return tnode;
    }
    int burnTree(Node *tnode) // O(n)
    {
        int tim = 0;

        queue<Node *> q;
        unordered_map<Node *, bool> vis; // tracks burnt node

        q.push(tnode);
        vis[tnode] = 1; // target node starts burning

        while (!q.empty())
        {
            bool burn = 0; // if burning happens
            int n = q.size();

            for (int i = 0; i < n; i++) // next burning nodes
            {
                Node *tem = q.front();
                q.pop();

                if (tem->left && !vis[tem->left]) // spreads fire to left child
                {
                    q.push(tem->left);
                    vis[tem->left] = 1;
                    burn = 1;
                }
                if (tem->right && !vis[tem->right]) // right child
                {
                    q.push(tem->right);
                    vis[tem->right] = 1;
                    burn = 1;
                }
                if (Parent[tem] && !vis[Parent[tem]]) // parent
                {
                    q.push(Parent[tem]);
                    vis[Parent[tem]] = 1;
                    burn = 1;
                }
            }
            // one second passed
            if (burn == 1) // if burning spreads
            {
                tim++;
            }
        }

        return tim;
    }

public:
    int minTime(Node *root, int target)
    {
        // code here
        Node *tnode = mapping(root, target); // finding target node & mapping

        return burnTree(tnode);
    }
};

// TC = O(n) average
// SC = O(n)

// https://www.geeksforgeeks.org/problems/burning-tree/1