class Solution
{
public:
    int reverseDegree(string s)
    {
        int sum = 0;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            sum += (i + 1) * (26 - (s[i] - 'a'));
        }

        return sum;
    }
};

// TC = O(n)
// SC = O(1)