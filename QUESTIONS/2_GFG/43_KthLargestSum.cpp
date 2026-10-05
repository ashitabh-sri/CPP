// https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

class Solution
{
public:
    int kthLargest(vector<int> &arr, int k)
    {
        // code here
        int n = arr.size();
        priority_queue<int, vector<int>, greater<int>> mnh; // min heap

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];

                if (mnh.size() < k)
                { // if haven't pushed k sums
                    mnh.push(sum);
                }
                else if (sum > mnh.top())
                { // maintain largest k sums
                    mnh.pop();
                    mnh.push(sum);
                }
            }
        }

        return mnh.top(); // Minimum from largest k sums = Kth largest sum
    }
};

// Kth Largest -> Min Heap
// TC = O(n^2 * logk)
// SC = O(k)