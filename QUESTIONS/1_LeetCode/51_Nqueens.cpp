class Solution
{
    bool isSafe(vector<string> &board, int row, int col, int n)
    {
        // Upper Rows of current column
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }

        // Upper-Left Diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        // Upper-Right Diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
    void solve(vector<string> &board, int row, int n, vector<vector<string>> &ans)
    {
        // Base Case
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, row, col, n))
            {                          // if safe to place queen at this position
                board[row][col] = 'Q'; // mark as placed

                solve(board, row + 1, n, ans); // explore other possiblities

                board[row][col] = '.'; // backtrack by unmarking
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(board, 0, n, ans);

        return ans;
    }
};

// Recursion & Backtracking
// TC = O(n! * n)
// SC = O(n) + O(n^2) = O(n^2) + output : S, S = total valid solutions of N-Queen