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
public:
    vector<int> topView(Node *root)
    {
        // code here
        vector<int> ans;

        unordered_map<int, int> mp; // track horizontal distance with node value
        int mnHd = 0, mxHd = 0;

        queue<pair<Node *, int>> q; // node, horizontal distance
        q.push({root, 0});
        while (!q.empty())
        {
            auto [node, hd] = q.front();
            q.pop();

            if (mp.find(hd) == mp.end()) // doesn't present any element in this hd
            {
                mp[hd] = node->data; // only insert first element of every hd
                mnHd = min(mnHd, hd);
                mxHd = max(mxHd, hd);
            }

            if (node->left)
            {
                q.push({node->left, hd - 1});
            }
            if (node->right)
            {
                q.push({node->right, hd + 1});
            }
        }

        for (int hd = mnHd; hd <= mxHd; hd++)
        {
            ans.push_back(mp[hd]);
        }

        return ans;
    }
};

// TC = O(n) average
// SC = O(n)

// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1