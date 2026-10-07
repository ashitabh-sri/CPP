// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution
{
private:
    void solve(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &vis, string &path, vector<string> &res)
    {
        int n = maze.size();

        if (x == n - 1 && y == n - 1) // Base Case
        {
            res.push_back(path);
            return;
        }

        vis[x][y] = 1; // mark as visited

        char dir[] = {'D', 'R', 'L', 'U'};
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};

        for (int i = 0; i < 4; i++) // four directions
        {
            int newx = x + dx[i];
            int newy = y + dy[i];

            if (newx >= 0 && newy >= 0 && newx < n && newy < n && maze[newx][newy] == 1 && vis[newx][newy] == 0)
            {
                path.push_back(dir[i]); // add the direction

                solve(maze, newx, newy, vis, path, res); // recursive call for further paths

                path.pop_back(); // backtrack by removing direction
            }
        }

        vis[x][y] = 0; // backtrack by unmarking
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();
        vector<string> res;

        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) // Edge Case
        {
            return res;
        }

        vector<vector<int>> vis(n, vector<int>(n, 0));
        string path;

        solve(maze, 0, 0, vis, path, res); // give possible paths

        sort(res.begin(), res.end()); // for lexographical order

        return res;
    }
};

// Recursion & BackTracking
// TC = O(4^(n*n) + PlogP*(n*n))
// SC = O(n*n) + ouput : O(P*(n*n)
// n*n = total cells in maze, P = total possible paths