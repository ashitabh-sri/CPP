// https://www.hackerrank.com/challenges/find-digits/problem?isFullScreen=true

int findDigits(int n)
{
    int ndiv = 0;

    int m = n;
    while (m != 0)
    {
        int dig = m % 10;
        if (dig != 0)
        {
            if (n % dig == 0)
            {
                ndiv++;
            }
        }
        m = m / 10;
    }

    return ndiv;
}