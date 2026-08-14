/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next; // for Middle in Odd nodes & First-Middle in Even nodes

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reversell(ListNode *head)
    {
        ListNode *cur = head;
        ListNode *pre = nullptr;

        while (cur != nullptr)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        return pre;
    }

public:
    bool isPalindrome(ListNode *head)
    {
        //  code here
        ListNode *mid = findMid(head);

        mid->next = reversell(mid->next);

        ListNode *head2 = mid->next;
        while (head2 != nullptr)
        {
            if (head->val != head2->val)
            {
                return false;
            }

            head = head->next;
            head2 = head2->next;
        }

        return true;
    }
};

// TC = O(n)
// SC = O(1)