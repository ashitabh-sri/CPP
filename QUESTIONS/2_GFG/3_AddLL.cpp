/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution
{
    Node *reversell(Node *head)
    {
        Node *pre = nullptr;
        while (head != nullptr)
        {
            Node *nxt = head->next;
            head->next = pre;
            pre = head;
            head = nxt;
        }

        return pre;
    }
    void InsTail(Node *&res, Node *&end, int val)
    {
        if (res == nullptr)
        {
            res = new Node(val);
            end = res;
        }
        else
        {
            Node *tem = new Node(val);
            end->next = tem;
            end = tem;
        }
    }
    Node *addll(Node *head1, Node *head2)
    {
        int carry = 0;
        Node *res = nullptr;
        Node *end = nullptr;

        while (head1 != nullptr || head2 != nullptr || carry != 0)
        {
            int data1 = 0;
            if (head1 != nullptr)
            {
                data1 = head1->data;
                head1 = head1->next;
            }

            int data2 = 0;
            if (head2 != nullptr)
            {
                data2 = head2->data;
                head2 = head2->next;
            }

            int sum = data1 + data2 + carry;
            int dig = sum % 10;
            InsTail(res, end, dig);
            carry = sum / 10;
        }

        return res;
    }

public:
    Node *addTwoLists(Node *head1, Node *head2)
    {
        // code here
        head1 = reversell(head1); // reverse linked list for adding
        head2 = reversell(head2); // with least significant digit

        Node *ans = addll(head1, head2); // addition of two linked lists

        ans = reversell(ans); // reverse linked list to get the acutal answer

        while (ans != nullptr && ans->next != nullptr && ans->data == 0)
        { // remove the leading zeroes
            Node *tem = ans;
            ans = ans->next;
            delete tem;
        }

        return ans;
    }
};