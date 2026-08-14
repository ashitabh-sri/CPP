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
    ListNode *reversell(ListNode *head)
    {
        if (head->next == NULL) // Base Case
        {
            return head;
        }

        ListNode *newhead = reversell(head->next);
        head->next->next = head; // make the next node pointing to itself
        head->next = NULL;       // breaking own link to avoid cycle

        return newhead;
    }

public:
    ListNode *reverseList(ListNode *head)
    {
        // Iterative Solution
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        // while(cur != NULL){
        //     ListNode* fwd = cur->next;
        //     cur -> next = pre;
        //     pre = cur;
        //     cur = fwd;
        // }
        // return pre;

        // Recursive Solution
        if (head == NULL) // Edge Case
        {
            return head;
        }

        return reversell(head);
    }
};

// Iterative Sol.
// TC = O(n), n = no. of nodes
// SC = O(1)

// Recursive Sol.
// TC = O(n), n = no. of nodes
// SC = O(n)