#include <iostream>
#include <queue>
using namespace std;

// Node of Binary Tree
class node
{
public:
    int val;
    node *left;
    node *right;

    node(int v)
    {
        val = v;
        left = right = nullptr;
    }
};

// Constructing Binary Tree
node *makeBT(node *root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return nullptr;
    }

    cout << "For left child insertion of " << data << endl;
    root->left = makeBT(root->left);

    cout << "For right child insertion of " << data << endl;
    root->right = makeBT(root->right);

    return root;
}

// Level Order Traversal : BFS (Breadth First Search) on Tree
void lot(node *root)
{
    queue<node *> ord;
    ord.push(root);
    ord.push(nullptr);

    while (!ord.empty())
    {
        node *tem = ord.front();
        ord.pop();

        if (tem == nullptr)
        {
            cout << '\n';

            if (!ord.empty())
            {
                ord.push(nullptr);
            }
        }
        else
        {
            cout << tem->val << " ";

            if (tem->left)
            {
                ord.push(tem->left);
            }
            if (tem->right)
            {
                ord.push(tem->right);
            }
        }
    }
}
// Reverse Level Order Traversal
// void reverseLOT(node *root)
// {
//     queue<node*> q; // for iteration
//     stack<vector<node*>> st; // for reverse order of levels
//     q.push(root);
//     while (!q.empty())
//     {
//         int n = q.size();
//         vector<node*> level; // stores current level
//         while (n--)
//         {
//             node* curr = q.front();
//             q.pop();
//             level.push_back(curr);
//             if (curr->left)
//                 q.push(curr->left);
//             if (curr->right)
//                 q.push(curr->right);
//         }
//         st.push(level);
//     }
//     while (!st.empty())
//     {
//         for (node* curr : st.top())
//         {
//             cout << curr->val << " ";
//         }
//         cout << '\n';
//         st.pop();
//     }
// }
// TC = O(n)
// SC = O(n)

// In Order Traversal : DFS (Depth First Search)
// L N R : Left Node Right
// Recursive Version
void iot(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    iot(root->left);
    cout << root->val << " ";
    iot(root->right);
}
// Iterative Version
// stack<Node*> st;
// Node* curr = root;
// while(curr != NULL || !st.empty())
// {
//     while(curr != NULL)
//     {
//         st.push(curr);
//         curr = curr->left;
//     }
//     curr = st.top();
//     st.pop();
//     cout << curr->data << " ";
//     curr = curr->right;
// }
// TC = O(n)
// SC = O(h), h = height of tree, O(n) for skewed tree

// Morris Traversal for In Order
vector<int> inOrder(node *root)
{
    vector<int> res;
    node *curr = root;

    while (curr != nullptr)
    {
        if (curr->left == nullptr) // // If no left child
        {
            res.push_back(curr->data); // visit this node
            curr = curr->right;        // and go right
        }
        else
        {
            // Find the inorder predecessor of curr = rightmost node of left subtree / last node to visit
            Node *prev = curr->left;
            while (prev->right != nullptr && prev->right != curr)
            {
                prev = prev->right; // keeps going right until..
            }

            if (prev->right == nullptr) // found the predecessor
            {
                prev->right = curr; // connect it with curr
                curr = curr->left;  // start traversing left subtree
            }
            else // reached to curr again
            {
                prev->right = nullptr;     // break the link prev -> curr to restore tree
                res.push_back(curr->data); // visit the curr node
                curr = curr->right;        // start traversing to right subtree
            }
        }
    }
    return res;
}
// TC = O(n)
// SC = O(1)

// Pre Order Traversal : DFS
// N L R : Node Left Right
// Recursive Version
void pre(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}
// Iterative Version
// stack<Node*> st;
// st.push(root);
// while(!st.empty())
// {
//     Node* curr = st.top();
//     st.pop();
//     cout << curr->data << " ";
//     if(curr->right)
//         st.push(curr->right);
//     if(curr->left)
//         st.push(curr->left);
// }
// TC = O(n)
// SC = O(h)

// Post Order Traversal : DFS
// L R N : Left Right Node
// Recursive Version
void post(node *root)
{
    if (root == nullptr)
    {
        return;
    }

    post(root->left);
    post(root->right);
    cout << root->val << " ";
}
// Iterative Version
// stack<Node*> s1;
// stack<Node*> s2;
// s1.push(root);
// while(!s1.empty())
// {
//     Node* curr = s1.top();
//     s1.pop();
//     s2.push(curr);
//     if(curr->left)
//         s1.push(curr->left);
//     if(curr->right)
//         s1.push(curr->right);
// }
// while(!s2.empty())
// {
//     cout << s2.top()->data << " ";
//     s2.pop();
// }
// TC = O(n)
// SC = O(h)

// Constructing BT from level order traversal
void *makeBTlev(node *&root)
{
    queue<node *> q;
    int data;
    cout << "Enter data for root: ";
    cin >> data;
    root = new node(data);
    q.push(root);

    while (!q.empty())
    {
        node *tem = q.front();
        q.pop();

        int leftd;
        cout << "Enter data for left child: ";
        cin >> leftd;
        if (leftd != -1)
        {
            tem->left = new node(leftd);
            q.push(tem->left);
        }

        int rightd;
        cout << "Enter data for left child: ";
        cin >> rightd;
        if (rightd != -1)
        {
            tem->right = new node(rightd);
            q.push(tem->right);
        }
    }
}

int main()
{
    node *root = nullptr;

    root = makeBT(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    cout << "\nlot Order Traversal: \n";
    lot(root);

    cout << "In Order Traversal: \n";
    iot(root);

    Node *root1 = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> res = inOrder(root1);
    cout << "\nUsing Morris Traversal for In Order:\n";
    for (int data : res)
    {
        cout << data << " ";
    }

    cout << "\nPre Order Traversal:\n";
    pre(root);

    cout << "\nPost Order Traversal:\n";
    post(root);

    root = nullptr;
    makeBTlev(root);

    return 0;
}