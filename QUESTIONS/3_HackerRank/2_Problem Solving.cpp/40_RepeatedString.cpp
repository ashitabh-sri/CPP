// https://www.hackerrank.com/challenges/repeated-string/problem?isFullScreen=true

int cnta(string s, int n)
{
    int frq = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            frq++;
    }
    return frq;
}
long repeatedString(string s, long n)
{
    long frq = 0;
    long nol = s.size();

    if (n <= nol)
        frq = cnta(s, n);

    else
    {
        frq = cnta(s, nol);
        frq *= floor(n / nol);
        n = n % nol;
        frq += cnta(s, n);
    }

    return frq;
}