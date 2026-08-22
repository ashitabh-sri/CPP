#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/arrays-introduction/problem?isFullScreen=true

int main()
{
    int s, i;
    cin >> s;
    int arr[s];

    for (i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    for (i = s - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }

    return 0;
}