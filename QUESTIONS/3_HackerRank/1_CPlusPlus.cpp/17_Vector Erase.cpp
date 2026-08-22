#include <bits/stdc++.h>
using namespace std;

// https://www.hackerrank.com/challenges/vector-erase/problem?isFullScreen=true

int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    int b;
    cin >> b;
    b--;
    nums.erase(nums.begin() + b);

    int c, d;
    cin >> c >> d;
    c--;
    d--;
    nums.erase(nums.begin() + c, nums.begin() + d);

    cout << nums.size() << endl;
    for (int j : nums)
    {
        cout << j << " ";
    }
    return 0;
}