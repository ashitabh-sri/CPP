// https://www.hackerrank.com/challenges/library-fine/problem?isFullScreen=true

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2)
{
    int fin = 0;

    if (y1 > y2)
        fin = 10000;
    else if (y1 == y2 && m1 > m2)
        fin = 500 * (m1 - m2);
    else if (y1 == y2 && m1 == m2 && d1 > d2)
        fin = 15 * (d1 - d2);

    return fin;
}