class Solution
{
    bool isSafe(vector<vector<char>> &board, int row, int col, char val)
    {
        // Current Row
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == val)
            {
                return false;
            }
        }

        // Current column
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == val)
            {
                return false;
            }
        }

        // Current Box (3 x 3)
        int Row = (row / 3) * 3; // start row of Grid
        int Col = (col / 3) * 3; // start column of Grid
        for (int i = Row; i < Row + 3; i++)
        {
            for (int j = Col; j < Col + 3; j++)
            {
                if (board[i][j] == val)
                {
                    return false;
                }
            }
        }

        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char val = '1'; val <= '9'; val++)
                    {
                        if (isSafe(board, i, j, val)) // is safe to put
                        {
                            board[i][j] = val; // try the digit

                            if (solve(board)) // if solved
                            {
                                return true; // end the search
                            }

                            board[i][j] = '.'; // otherwise, backtrack by emptying cell
                        }
                    }

                    return false; // no solution find even after trying every val
                }
            }
        }

        return true; // no empty cell left
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

// Recursion & Backtracking
// TC = O(9^E)
// SC = O(E) , E = no. of empty cells