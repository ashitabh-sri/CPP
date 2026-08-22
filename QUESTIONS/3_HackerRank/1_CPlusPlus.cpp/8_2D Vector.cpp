#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true

int main()
{
    int n, q;
    cin >> n >> q;

    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        int s;
        cin >> s;

        for (int j = 0; j < s; j++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }

        vec.push_back(v);
    }

    int r, c;
    for (int i = 0; i < q; i++)
    {
        cin >> r >> c;
        cout << vec[r][c] << endl;
    }

    return 0;
}