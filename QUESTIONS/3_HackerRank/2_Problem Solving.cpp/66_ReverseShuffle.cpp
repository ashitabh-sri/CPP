// https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem

string reverseShuffleMerge(string s)
{

    vector<int> freq(26, 0);

    for (char c : s)
    {
        freq[c - 'a']++;
    }

    vector<int> required(26);

    for (int i = 0; i < 26; i++)
    {
        required[i] = freq[i] / 2;
    }

    vector<int> used(26, 0);
    vector<int> remaining = freq;

    string ans;

    for (int i = s.size() - 1; i >= 0; i--)
    {

        char c = s[i];
        int idx = c - 'a';

        remaining[idx]--;

        // Already have enough of this character
        if (used[idx] == required[idx])
            continue;

        // Maintain lexicographically smallest answer
        while (!ans.empty() &&
               ans.back() > c &&
               used[ans.back() - 'a'] - 1 + remaining[ans.back() - 'a'] >= required[ans.back() - 'a'])
        {

            used[ans.back() - 'a']--;
            ans.pop_back();
        }

        ans.push_back(c);
        used[idx]++;
    }

    return ans;
}