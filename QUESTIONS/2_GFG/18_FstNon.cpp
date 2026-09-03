class Solution
{
public:
    string firstNonRepeating(string &s)
    {
        // code here
        string ans = "";

        int n = s.size();
        int frq[26] = {};
        queue<char> alp;

        for (int i = 0; i < n; i++) // O(n)
        {
            char c = s[i];
            frq[c - 'a']++;
            alp.push(c);

            while (!alp.empty() && frq[alp.front() - 'a'] > 1) // O(n) at most not for every i
            {
                alp.pop();
            }

            if (alp.empty())
            {
                ans.push_back('#');
            }
            else
            {
                ans.push_back(alp.front());
            }
        }

        return ans;
    }
};

// TC = O(n + n) = O(2n) = O(n)
// SC = O(n)

// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1