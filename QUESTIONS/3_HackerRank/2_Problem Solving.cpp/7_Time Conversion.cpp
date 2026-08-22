// https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true

string timeConversion(string s)
{

    string m = s;

    if (m[8] == 'A')
    {
        if (m[0] == '1' && m[1] == '2')
        {
            m[0] = '0';
            m[1] = '0';
        }
    }

    else if (m[8] = 'P')
    {
        if (m[0] == '1' && m[1] == '2')
        {
        }
        else
        {
            m[0] += 1;
            m[1] += 2;
        }
    }

    m.erase(8, 2);
    return m;
}