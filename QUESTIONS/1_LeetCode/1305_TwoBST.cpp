class Solution
{
    void pushLeft(TreeNode *root, stack<TreeNode *> &st) // push the left path nodes
    {
        while (root)
        {
            st.push(root);
            root = root->left;
        }
    }

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans;

        stack<TreeNode *> s1, s2;
        // Put the smallest element of each BST on top
        pushLeft(root1, s1);
        pushLeft(root2, s2);

        while (!s1.empty() || !s2.empty())
        {
            // If stack2 is empty OR sorting condition
            if (s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val))
            {

                TreeNode *node = s1.top();
                s1.pop();
                ans.push_back(node->val);

                pushLeft(node->right, s1); // Prepare next inorder element
            }
            else // if stack1 is empty
            {
                TreeNode *node = s2.top();
                s2.pop();
                ans.push_back(node->val);

                pushLeft(node->right, s2); // Prepare next inorder element
            }
        }

        return ans;
    }
};

// BST Inorder -> Sorted + Two Stacks Merge
// TC = O(m + n), total nodes in trees
// SC = O(h1 + h2), total height of trees