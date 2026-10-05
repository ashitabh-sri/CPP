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
    struct Compare
    {
        bool operator()(ListNode *a, ListNode *b) // define compare for min heap
        {
            return a->val > b->val; // True if a's val is smaller => Smaller gets priority
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, Compare> mnh; // min heap

        for (ListNode *root : lists)
        {
            if (root != nullptr)
            {
                mnh.push(root);
            }
        }

        ListNode dummy(-1);
        ListNode *tail = &dummy;

        while (!mnh.empty())
        {
            ListNode *tem = mnh.top(); // node with min value
            mnh.pop();

            tail->next = tem; // push into ans
            tail = tail->next;

            if (tem->next != nullptr)
            {
                mnh.push(tem->next);
            }
        }

        return dummy.next;
    }
};

// Min Heap
// TC = O(nlogk), n = total nodes
// SC = O(k)