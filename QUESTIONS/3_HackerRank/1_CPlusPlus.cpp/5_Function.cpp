#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/c-tutorial-functions/problem?isFullScreen=true

int great(int a, int b, int c, int d)
{
       int max = a > b ? (a > c ? (a > d ? a : d) : (c > d ? c : d)) : (b > c ? (b > d ? b : d) : (c > d ? c : d));
       return max;
}

int main()
{
       int a, b, c, d;
       cin >> a >> b >> c >> d;

       cout << great(a, b, c, d);

       return 0;
}