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
    void InsTail(ListNode *&res, ListNode *&end, int dig)
    {
        if (res == nullptr)
        {
            res = new ListNode(dig);
            end = res;
        }
        else
        {
            ListNode *tem = new ListNode(dig);
            end->next = tem;
            end = tem;
        }
    }
    ListNode *addll(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *res = nullptr;
        ListNode *end = nullptr;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int data1 = 0;
            if (l1 != nullptr)
            {
                data1 = l1->val;
                l1 = l1->next;
            }

            int data2 = 0;
            if (l2 != nullptr)
            {
                data2 = l2->val;
                l2 = l2->next;
            }

            int sum = data1 + data2 + carry;
            int dig = sum % 10;
            InsTail(res, end, dig);
            carry = sum / 10;
        }

        return res;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = addll(l1, l2); // addition of two linked lists

        return ans;
    }
};

// TC = O(n)
// SC = O(n)