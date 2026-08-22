// https://www.hackerrank.com/challenges/save-the-prisoner/problem?isFullScreen=true

int saveThePrisoner(int n, int m, int s)
{
    return (((s - 1 + m - 1) % n) + 1);
}