/* Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
    pair<bool, int> isSumT(Node *root)
    {
        if (root == nullptr) // Null node
        {
            return {true, 0};
        }

        if (root->left == nullptr && root->right == nullptr) // Leaf Node
        {
            return {true, root->data};
        }

        pair<bool, int> lef = isSumT(root->left);
        if (!lef.first) // Sum Tree logic failed
        {
            return {false, 0}; // no need for further calculations
        }
        pair<bool, int> rig = isSumT(root->right);
        if (!rig.first)
        {
            return {false, 0};
        }

        int lefSum = lef.second, rigSum = rig.second;
        bool chk = (root->data == lefSum + rigSum);

        pair<int, int> ans;
        ans.first = lef.first && rig.first && chk;
        ans.second = root->data + lefSum + rigSum;

        return ans;
    }

public:
    bool isSumTree(Node *node)
    {
        // code here
        return isSumT(node).first;
    }
};

// TC = O(n)
// SC = O(h)

// https://www.geeksforgeeks.org/problems/sum-tree/1