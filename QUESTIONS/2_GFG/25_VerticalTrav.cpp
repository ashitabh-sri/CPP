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
    vector<vector<int>> verticalOrder(Node *root)
    {
        // code here
        vector<vector<int>> ans;

        unordered_map<int, vector<int>> mp;
        int mnHd = 0, mxHd = 0;
        // map<int, vector<int>> mp; // horizontal distance -> nodes
        queue<pair<Node *, int>> q; // node, horizontal distance

        q.push({root, 0});
        while (!q.empty()) // O(n) Level Order Traversal (BFS)
        {
            auto [node, hd] = q.front();
            q.pop();

            mp[hd].push_back(node->data); // O(logn) if map, O(1) if unordered_map

            mnHd = min(mnHd, hd);
            mxHd = max(mxHd, hd);

            if (node->left)
            {
                q.push({node->left, hd - 1}); // going left means behind from origin
            }
            if (node->right)
            {
                q.push({node->right, hd + 1}); // going right means forward from origin
            }
        }

        for (int hd = mnHd; hd <= mxHd; hd++)
        {
            ans.push_back(mp[hd]);
        }

        // for(auto &it : mp) // O(h), sorts based on hd, from left to right
        // {
        //     ans.push_back(it.second);
        // }

        return ans;
    }
};

// TC = O(n) average
// TC = O(n * logn) + O(h) = O(nlogn)
// SC = O(n)

// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1