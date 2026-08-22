// https://www.hackerrank.com/challenges/append-and-delete/problem?isFullScreen=true

string appendAndDelete(string s, string t, int k)
{
    int lenS = s.size(), lenT = t.size();
    if (k >= lenS + lenT)
    {
        return "Yes";
    }
    int rightlen = 0;
    for (int j = 0; j < min(lenS, lenT); j++)
    {
        if (s[j] == t[j])
        {
            rightlen++;
        }
        else
        {
            break;
        }
    }
    int minop = (lenS - rightlen) + (lenT - rightlen);
    else if (k >= minop && (k - minop) % 2 == 0)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}