// https://www.hackerrank.com/challenges/morgan-and-a-string/problem?isFullScreen=true

string morganAndString(string a, string b)
{
    a += '{';
    b += '{';

    string ans;
    int i = 0, j = 0;

    while (i < a.size() - 1 || j < b.size() - 1)
    {
        if (a.compare(i, a.size() - i, b, j, b.size() - j) < 0)
            ans += a[i++];
        else
            ans += b[j++];
    }

    return ans;
}