class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // nth_element(nums.begin(), nums.begin() + k-1, nums.end(), greater<int>());
        // return nums[k - 1];

        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> mnh; // min heap

        for (int i = 0; i < k; i++)
        {                      // pushing first k elements
            mnh.push(nums[i]); // into heap
        }
        for (int i = k; i < n; i++)
        {
            if (nums[i] > mnh.top())
            {
                mnh.pop();         // maintain largest k elements
                mnh.push(nums[i]); // of array in heap
            }
        }

        return mnh.top(); // Minimum of largest k = Kth largest of array
    }
};

// Kth Largest -> Min Heap (& Vice Versa)
// TC = O(nlogk)
// SC = O(k)