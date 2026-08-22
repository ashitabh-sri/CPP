// https://www.hackerrank.com/challenges/abbr/problem

string abbreviation(string a, string b)
{

    int n = a.size();
    int m = b.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true;

    // If b is empty, a can only be deleted if all are lowercase
    for (int i = 1; i <= n; i++)
    {

        if (islower(a[i - 1]))
            dp[i][0] = dp[i - 1][0];
        else
            dp[i][0] = false;
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= m; j++)
        {

            char ca = a[i - 1];
            char cb = b[j - 1];

            // Characters match directly
            if (toupper(ca) == cb)
            {

                // Convert/use character
                dp[i][j] = dp[i - 1][j - 1];

                // If lowercase, we can also delete it
                if (islower(ca))
                {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
            else
            {

                // Cannot use uppercase mismatching character
                if (islower(ca))
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }

    return dp[n][m] ? "YES" : "NO";
}