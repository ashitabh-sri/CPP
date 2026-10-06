class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = "";
        int n = strs.size();
        const string &st1 = strs[0];
        int n1 = st1.size();

        for (int i = 0; i < n1; i++)
        { // First String Size = Maximum Longest Common Prefix Size
            for (int j = 1; j < n; j++)
            {
                const string &st2 = strs[j];

                if (st2.size() == 0)
                { // Empty String
                    return "";
                }

                if (i >= st2.size() || st1[i] != st2[i])
                {
                    return res;
                }
            }
            res += st1[i];
        }

        return res;
    }
};

// TC = O(n*m) : No. of Strings x Length of Prefix
// SC = O(1) : excluding output string