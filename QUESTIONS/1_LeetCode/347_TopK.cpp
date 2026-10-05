class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mpp;
        for (int num : nums)
        {
            mpp[num]++;
        }

        // Total Frequencies possible = Size of nums + 1
        vector<vector<int>> bucket(nums.size() + 1); // 2D vector for num with same frequencies
        for (auto [num, frq] : mpp)
        {
            bucket[frq].push_back(num); // push into bucket as per frequency
        }

        vector<int> ans;

        for (int i = nums.size(); i >= 0; i--)
        { // start from max frequency
            for (int num : bucket[i])
            {
                ans.push_back(num);
            }

            if (ans.size() == k)
            {
                break;
            }
        }

        return ans;
    }
};

// Hashing, Bucket Sort
// TC = O(n)
// SC = O(n)