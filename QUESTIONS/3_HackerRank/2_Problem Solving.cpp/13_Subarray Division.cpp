// https://www.hackerrank.com/challenges/the-birthday-bar/problem?isFullScreen=true

int birthday(vector<int> s, int d, int m)
{
    int ndiv = 0;

    int lim = s.size() - m;
    for (long unsigned int i = 0; i <= lim; i++)
    {
        int sum = s.at(i);

        for (int j = i + 1; j <= i + m - 1; j++)
        {
            sum += s.at(j);
        }

        if (sum == d)
        {
            ndiv++;
        }
    }

    return ndiv;
}