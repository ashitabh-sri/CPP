class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int cnt = nums[0];
        int sum = 0;
        int i = 0;
        int n = nums.size();

        while (i < n)
        {
            if (nums[i] == cnt)
            {
                sum += nums[i];
                cnt++;
                i++;
            }
            else
            {
                break;
            }
        }
        int x = sum;

        unordered_set<int> stt;
        for (int a : nums)
        {
            stt.insert(a);
            i++;
        }

        while (stt.count(x))
        {
            x++;
        }

        return x;
    }
};

// TC = O(n)
// SC = O(n)