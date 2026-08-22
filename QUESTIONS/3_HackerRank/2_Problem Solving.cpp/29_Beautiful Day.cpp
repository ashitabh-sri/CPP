// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem?isFullScreen=true

int beautifulDays(int i, int j, int k)
{
    int beautdays = 0;

    for (int x = i; x <= j; x++)
    {
        int day = x;

        int rev = 0, r = 0;
        while (day != 0)
        {
            r = day % 10;
            rev = rev * 10 + r;
            day = day / 10;
        }

        int diff = abs(x - rev);
        if (diff % k == 0)
        {
            beautdays++;
        }
    }

    return beautdays;
}