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
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *cur = nullptr; // head of smaller valued ll
        ListNode *nxt = nullptr; // next node of chosen ll
        ListNode *beg = nullptr; // head of other ll

        if ((list1->val) <= (list2->val))
        {
            cur = list1;
            nxt = cur->next;
            beg = list2;
        }
        else
        {
            cur = list2;
            nxt = cur->next;
            beg = list1;
        }
        ListNode *newhead = cur; // saving the head of merged ll

        while (nxt != nullptr && beg != nullptr) // comparing till there are nodes
        {
            if ((beg->val) <= (nxt->val))
            {
                cur->next = beg;
                beg = beg->next;
                cur = cur->next;
            }
            else
            {
                cur->next = nxt;
                nxt = nxt->next;
                cur = cur->next;
            }
        }

        cur->next = (nxt == nullptr) ? beg : nxt;

        return newhead;
    }
};

// TC = O(n + m), no. of nodes : list1 + list2
// SC = O(1)