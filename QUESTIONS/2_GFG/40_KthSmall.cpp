// https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1

class Solution
{
public:
    int kthSmallest(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        priority_queue<int> mxh; // max heap

        for (int i = 0; i < k; i++)
        { // push first k elements into max heap
            mxh.push(arr[i]);
        }
        for (int i = k; i < n; i++)
        { // if any remained element is smaller
            if (arr[i] < mxh.top())
            {
                mxh.pop();        // pop the top
                mxh.push(arr[i]); // push that element
            }
        }

        return mxh.top(); // Top = Kth smallest
    }
};

// Kth Smallest -> Max Heap (& Vice-versa)
// TC = O(nlogk)
// SC = O(k)