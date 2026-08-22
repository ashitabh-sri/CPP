// https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true

long arrayManipulation(int n, vector<vector<int>> queries)
{
    vector<long> diff(n + 2, 0);

    for (auto &q : queries)
    {
        int a = q[0];
        int b = q[1];
        int k = q[2];

        diff[a] += k;
        diff[b + 1] -= k;
    }

    long maximum = 0;
    long current = 0;

    for (int i = 1; i <= n; i++)
    {
        current += diff[i];
        maximum = max(maximum, current);
    }

    return maximum;
}