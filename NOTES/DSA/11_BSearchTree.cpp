#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

Node *InsBST(Node *root, int d)
{
    if (root == nullptr)
    {
        root = new Node(d);
        return root;
    }

    if (d < root->data) // smaller data goes to left
    {
        root->left = InsBST(root->left, d);
    }
    else // equal or greater data goes to right
    {
        root->right = InsBST(root->right, d);
    }

    return root;
}
// TC = O(h), Balanced BST : O(logn), Skewed BST : O(n)

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = InsBST(root, data);
        cin >> data;
    }
}

// Level Order Traversal : BFS on Tree
void lot(Node *root)
{
    queue<Node *> ord;
    ord.push(root);
    ord.push(nullptr);

    while (!ord.empty())
    {
        Node *tem = ord.front();
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
            cout << tem->data << " ";

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
// TC = O(n)
// SC = O(n)

// In Order Traversal : DFS on Tree
// L N R : Left Node Right
// gives in Sorted Order for BST
void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// TC = O(n)
// SC = O(h), h = height of tree, O(n) for skewed tree

// Pre Order Traversal : DFS
// N L R : Node Left Right
void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// TC = O(n)
// SC = O(h)

// Post Order Traversal : DFS
// L R N : Left Right Node
void postorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
// TC = O(n)
// SC = O(h)

Node *DelBST(Node *root, int val)
{
    // base case
    if (root == nullptr)
    {
        return root;
    }

    // found node to delete
    if (root->data == val)
    {
        // 0 child
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }

        // 1 child
        if (root->left != nullptr && root->right == nullptr) // left child
        {
            Node *tem = root->left;
            delete root;
            return tem;
        }
        if (root->left == nullptr && root->right != nullptr) // right child
        {
            Node *tem = root->right;
            delete root;
            return tem;
        }

        // 2 child
        if (root->left != nullptr && root->right != nullptr)
        {
            // find Inorder predecessor (max in left subtree) / successor (min in right subtree)
            Node *pre = root->left; // goes to left subtree
            while (pre->right)
            {
                pre = pre->right; // finds max
            }

            root->data = pre->data;                     // replace node data with it
            root->left = DelBST(root->left, pre->data); // delete that predecessor node
            return root;
        }
    }
    // node in left subtree
    else if (root->data > val)
    {
        root->left = DelBST(root->left, val);
        return root;
    }
    // node in right subtree
    else
    {
        root->right = DelBST(root->right, val);
        return root;
    }
}
// TC = O(h)
// SC = O(1)

int main()
{
    Node *root = nullptr;

    cout << "Enter data to create BST: ";
    takeInput(root); // stops taking inputs at -1

    cout << "\nPrinting BST in Level Order: \n";
    lot(root);

    cout << "\nPrinting BST with In order: \n";
    inorder(root);

    cout << "\nPrinting BST with Pre order: \n";
    preorder(root);

    cout << "\nPrinting BST with Post order: \n";
    postorder(root);

    cout << "\nEnter Node value to delete from BST: \n";
    int val;
    cin >> val;
    while (val != -1)
    {
        DelBST(root, val);
        cout << "\nPrinting BST in Level Order: \n";
        lot(root);
        cout << "\nEnter another Node value to delete from BST: \n";
        cin >> val;
    }

    return 0;
}