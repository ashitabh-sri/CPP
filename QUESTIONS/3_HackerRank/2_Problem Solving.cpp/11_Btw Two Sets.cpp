// https://www.hackerrank.com/challenges/between-two-sets/problem?isFullScreen=true

int getTotalX(vector<int> a, vector<int> b)
{
    int ans = 0;

    int s1 = a.size();
    auto max1 = max_element(a.begin(), a.end());
    int max = *max1;

    int s2 = b.size();

    for (int i = max; i <= 100; i++)
    {
        int p = 0;
        for (int j = 0; j < s1; j++)
        {
            int q = a.at(j);
            p += i % q;
        }

        if (p == 0)
        {
            int r = 0;
            for (int k = 0; k < s2; k++)
            {
                int s = b.at(k);
                r += s % i;
            }
            if (r == 0)
            {
                ans++;
            }
        }
    }

    return ans;
}