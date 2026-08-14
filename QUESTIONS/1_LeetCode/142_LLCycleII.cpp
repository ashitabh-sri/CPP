/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool chk = false;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                chk = true;
                break;
            }
        }

        if (!chk)
        {
            return nullptr;
        }

        slow = head;
        while (slow != fast) // A = kc - B
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

/*
Distance by FAST Pointer = 2 * Distance by SLOW Pointer
A + x*C + B = 2 * (A + y*C + B)
Final Formula : A + B = k * C
where, A = Distance from head to cycle start node
B = cycle start node to Meeting node of SLOW & FAST
k = x - 2y (constant)
C = distance of one cycle in ll
*/

// TC = O(n)
// SC = O(1)