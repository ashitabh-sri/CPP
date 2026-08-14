/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution
{
    Node *findMid(Node *head)
    {
        Node *slow = head;
        Node *fast = head->next; // for Middle in Odd nodes & First-Middle in Even nodes

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node *reversell(Node *head)
    {
        Node *cur = head;
        Node *pre = nullptr;

        while (cur != nullptr)
        {
            Node *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }

public:
    bool isPalindrome(Node *head)
    {
        //  code here
        Node *mid = findMid(head);

        mid->next = reversell(mid->next);

        Node *head2 = mid->next;
        while (head2 != nullptr)
        {
            if (head->data != head2->data)
            {
                return false;
            }

            head = head->next;
            head2 = head2->next;
        }

        return true;
    }
};