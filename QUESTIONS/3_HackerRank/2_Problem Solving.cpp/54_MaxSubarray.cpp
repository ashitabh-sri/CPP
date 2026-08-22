// https://www.hackerrank.com/challenges/maximum-subarray-sum/problem

long maximumSum(vector<long> a, long m)
{
    set<long> prefixSet;
    long prefix = 0;
    long ans = 0;

    for (long x : a)
    {
        prefix = (prefix + x) % m;
        ans = max(ans, prefix);

        auto it = prefixSet.upper_bound(prefix);

        if (it != prefixSet.end())
        {
            ans = max(ans, (prefix - *it + m) % m);
        }

        prefixSet.insert(prefix);
    }

    return ans;
}