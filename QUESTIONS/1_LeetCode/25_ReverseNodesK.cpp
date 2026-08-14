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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *newhead = NULL; // head of final reversed ll

        int len = 0;
        ListNode *tem = head;
        while (tem != NULL)
        {
            len++; // total no. of nodes in ll
            tem = tem->next;
        }

        int grp = len / k;       // total no. of group to reverse
        ListNode *prvend = NULL; // previous group end

        ListNode *cur = head;
        while (grp--)
        {
            ListNode *beg = cur; // group beg

            ListNode *pre = NULL;
            for (int cnt = 1; cnt <= k; cnt++)
            {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }

            if (newhead == NULL)
            {
                newhead = pre; // .. = 1st group reversal pre
            }

            if (prvend != NULL)
            {
                prvend->next = pre; // tail of previous reversed ll -> head of current reversed ll
            }

            prvend = beg; // update by current reversed group tail
        }

        prvend->next = cur; // connect to remaining nodes

        return newhead;
    }
};

// TC = O(n)
// SC = O(1)