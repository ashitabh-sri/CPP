// https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen=true

string kangaroo(int x1, int v1, int x2, int v2)
{

    string kang = "NO";
    int dist1, dist2;

    for (int i = 1; i < 10000000; i++)
    {

        dist1 = (i * v1) + x1;

        dist2 = (i * v2) + x2;

        if (dist1 == dist2)
        {
            kang = "YES";
            break;
        }
    }

    return kang;
}