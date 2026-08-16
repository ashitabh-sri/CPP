class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size();
        int mxl = 1;

        vector<int> frq(26, 0);
        int L = 0, R = 0;
        while (R < n)
        {
            frq[s[R] - 'a']++;

            while (frq[s[R] - 'a'] > 2)
            {
                frq[s[L] - 'a']--;
                L++;
            }

            mxl = max(mxl, R - L + 1);
            R++;
        }

        return mxl;
    }
};

// TC = O(n)
// SC = O(1)