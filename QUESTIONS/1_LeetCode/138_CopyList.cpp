/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *cur = head;

        // create & insert copies in btw next link
        while (cur)
        {
            Node *copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // assign random ptrs
        cur = head;
        while (cur)
        {
            cur->next->random = cur->random ? cur->random->next : cur->random;
            cur = cur->next->next;
        }

        // fix next link and make clone ll
        Node dummy(0); // dummy node
        Node *temp = &dummy;
        cur = head;
        while (cur && cur->next)
        {
            temp->next = cur->next;
            temp = temp->next;

            cur->next = cur->next->next;
            cur = cur->next;
        }

        return dummy.next;
    }
};

// TC = O(n)
// SC = Output Space : O(n), Auxiliary Space : O(1)