class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k)
    {
        // code here
        vector<int> ans;

        int n = arr.size();
        deque<int> neg;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                neg.push_back(i); // store negative num index
            }

            if (!neg.empty() && neg.front() <= i - k) // out of window index
            {
                neg.pop_front();
            }

            if (i >= k - 1) // window completed
            {
                if (!neg.empty())
                {
                    ans.push_back(arr[neg.front()]);
                }
                else
                {
                    ans.push_back(0);
                }
            }
        }

        return ans;
    }
};

// TC = O(n)
// SC = O(n), Auxiliary Space = O(k)

// https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1