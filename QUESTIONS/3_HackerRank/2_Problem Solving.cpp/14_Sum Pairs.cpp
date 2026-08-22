// https://www.hackerrank.com/challenges/divisible-sum-pairs/problem?isFullScreen=true

int divisibleSumPairs(int n, int k, vector<int> ar)
{
    int npair = 0;

    for (int i = 0; i < n - 1; i++)
    {

        for (int j = i + 1; j < n; j++)
        {
            int sum = ar.at(i) + ar.at(j);

            if (sum % k == 0)
            {
                npair++;
            }
        }
    }

    return npair;
}