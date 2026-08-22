// https://www.hackerrank.com/challenges/utopian-tree/problem?isFullScreen=true

int utopianTree(int n)
{
    int treeh = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            treeh *= 2;
        }
        if (i % 2 == 0)
        {
            treeh += 1;
        }
    }

    return treeh;
}