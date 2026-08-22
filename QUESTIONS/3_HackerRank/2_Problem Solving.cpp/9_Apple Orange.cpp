// https://www.hackerrank.com/challenges/apple-and-orange/problem?isFullScreen=true

void countApplesAndOranges(int s, int t, int a, int b, vector<int> apples, vector<int> oranges)
{

    int q = 0;
    for (int i = 0; i < apples.size(); i++)
    {
        int p = a + apples[i];

        if (p >= s && p <= t)
        {
            q++;
        }
    }

    int y = 0;
    for (int j = 0; j < oranges.size(); j++)
    {
        int x = b + oranges[j];

        if (x >= s && x <= t)
        {
            y++;
        }
    }

    cout << q << "\n"
         << y;
}