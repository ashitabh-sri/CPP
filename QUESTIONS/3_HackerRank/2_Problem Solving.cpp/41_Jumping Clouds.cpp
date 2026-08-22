// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?isFullScreen=true

int jumpingOnClouds(vector<int> c)
{
    if (c.size() == 2)
        return 1;

    int minj = 0;
    int pos = 0, end = c.size() - 1;

    while (pos != end)
    {
        if (c[pos + 2] == 0)
        {
            minj++;
            pos += 2;
        }
        else
        {
            minj++;
            pos++;
        }

        if (pos + 1 == end)
        {
            minj++;
            break;
        }
    }

    return minj;
}