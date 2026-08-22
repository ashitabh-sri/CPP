#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/c-tutorial-pointer/problem?isFullScreen=true

void fun(int *x, int *y)
{
    int temp = *x;
    *x = *x + *y;
    *y = abs(temp - *y);
}

int main()
{
    int a, b;
    cin >> a >> b;

    fun(&a, &b);
    cout << a << endl
         << b;

    return 0;
}