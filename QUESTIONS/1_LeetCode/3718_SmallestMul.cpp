class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        unordered_set<int> val;
        for (int num : nums)
        {
            val.insert(num);
        }

        int k1 = k;
        while (true)
        {
            if (!val.count(k1))
            {
                return k1;
            }

            k1 += k;
        }

        return 0;
    }
};

// TC = O(n)
// SC = O(n)