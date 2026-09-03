#include <bits/stdc++.h>
using namespace std;

// Top-Down = Recursion + Memoization)
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

// Bottom-Up = Tabulation
int fib1(int n)
{
    int dp[n + 1];
    if (n <= 1)
        dp[n] = n;

    for (int i = 2; i <= n; i++)
        dp[i] = fib1(i - 1) + fib1(i - 2);

    return dp[n];
}

// Space Optimization
int fib3(int n)
{
    int prev0 = 0;
    int prev1 = 1;
    if (n == 0)
        return prev0;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev0;
        prev0 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    // Fibbonacci Series
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++)
        dp[i] = -1;

    cout << fib(n, dp) << endl
         << fib1(n) << endl
         << fib3(n) << "\n\n";

    return 0;
}