class Solution
{
    bool isSafe(vector<vector<int>> &board, int row, int col, int n)
    {
        // Upper Rows of current column
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 1)
            {
                return false;
            }
        }

        // Upper-Left Diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }

        // Upper-Right Diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 1)
            {
                return false;
            }
        }

        return true;
    }
    void solve(vector<vector<int>> &board, int row, int n, int &ans)
    {
        // Base Case
        if (row == n)
        {
            ans++;
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, row, col, n))
            {                        // if safe to place queen at this position
                board[row][col] = 1; // mark as placed

                solve(board, row + 1, n, ans); // explore other possiblities

                board[row][col] = 0; // backtrack by unmarking
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        int ans = 0;
        vector<vector<int>> board(n, vector<int>(n, 0));

        solve(board, 0, n, ans);

        return ans;
    }
};

// Recursion & Backtracking
// TC = O(n! * n), Possible Arrangements * isSafe Work
// SC = O(n) + O(n^2) = O(n^2), Recursive Stack + Board space