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
private:
    // Recursive Soln
    // ListNode* findMid(ListNode* head){
    //     ListNode* slow = head;
    //     ListNode* fast = head->next;

    //     while(fast && fast->next){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }

    //     return slow;
    // }

    ListNode *split(ListNode *head, int size)
    {
        for (int i = 1; head && i < size; i++)
        {
            head = head->next;
        }

        if (!head) // not enough nodes for right block
        {
            return nullptr;
        }

        ListNode *second = head->next; // head of right block
        head->next = nullptr;          // split the list

        return second;
    }

    ListNode *merge(ListNode *lef, ListNode *rig)
    {
        ListNode dummy(-1);
        ListNode *tem = &dummy;

        while (lef && rig)
        {
            if (lef->val <= rig->val)
            {                    // sort and..
                tem->next = lef; // ..connect to..
                lef = lef->next;
            }
            else
            {
                tem->next = rig; // merged list
                rig = rig->next;
            }

            tem = tem->next;
        }

        tem->next = lef ? lef : rig; // connect to remaining nodes of which one's remain

        return dummy.next; // return head of merged blocks of ll
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !(head->next)) // Edge cases : Empty list or One node in list
        {
            return head;
        }

        // Find size of list
        int n = 0;
        ListNode *cur = head;
        while (cur)
        {
            n++;
            cur = cur->next;
        }

        ListNode dummy(-1);                     // dummy node for result list
        dummy.next = head;                      // connect to input list
        for (int size = 1; size < n; size *= 2) // size of splitting blocks
        {
            ListNode *pre = &dummy; // keep track of result list

            cur = dummy.next;
            while (cur)
            {
                ListNode *lef = cur;              // head of left block
                ListNode *rig = split(lef, size); // head of right block

                cur = split(rig, size); // head of remaining list

                ListNode *merged = merge(lef, rig); // sort & merge both blocks

                pre->next = merged; // connect to result list
                while (pre->next)   // update to last node of new merged block
                {
                    pre = pre->next;
                }
            }
        }

        return dummy.next; // return head of sorted list

        // Recursive Soln
        // ListNode* mid = findMid(head); // give middle of list
        // ListNode* lef = head; // left part
        // ListNode* rig = mid->next; // right part
        // mid->next = nullptr; // split the list into two

        // lef = sortList(lef); // recursive calls..
        // rig = sortList(rig); // ..to split

        // return merge(lef, rig); // return head of sorted + merged parts of list
    }
};

// Iterative Soln
// TC = O(nlogn)
// SC = O(1)

// Recursive Soln
// TC = O(nlogn)
// SC = O(logn)