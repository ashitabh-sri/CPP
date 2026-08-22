class Solution
{
private:
    void solve(vector<vector<int>> &maze, int x, int y, vector<vector<int>> vis,
               string pth, vector<string> &res)
    {
        int n = maze.size();
        // Base Case
        if (x == n - 1 && y == n - 1)
        {
            res.push_back(pth);
            return;
        }

        vis[x][y] = 1;

        // Down
        int newx = x + 1;
        int newy = y;
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && vis[newx][newy] == 0 && maze[newx][newy] == 1)
        {
            pth.push_back('D');
            solve(maze, newx, newy, vis, pth, res);
            pth.pop_back();
        }

        // Right
        newx = x;
        newy = y + 1;
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && vis[newx][newy] == 0 && maze[newx][newy] == 1)
        {
            pth.push_back('R');
            solve(maze, newx, newy, vis, pth, res);
            pth.pop_back();
        }

        // Left
        newx = x;
        newy = y - 1;
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && vis[newx][newy] == 0 && maze[newx][newy] == 1)
        {
            pth.push_back('L');
            solve(maze, newx, newy, vis, pth, res);
            pth.pop_back();
        }

        // Up
        newx = x - 1;
        newy = y;
        if (newx >= 0 && newy >= 0 && newx < n && newy < n && vis[newx][newy] == 0 && maze[newx][newy] == 1)
        {
            pth.push_back('U');
            solve(maze, newx, newy, vis, pth, res);
            pth.pop_back();
        }

        vis[x][y] = 0;
    }

public:
    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        // code here
        vector<string> res;
        string pth;
        int srcx = 0;
        int srcy = 0;

        int n = maze.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        solve(maze, srcx, srcy, vis, pth, res);
        sort(res.begin(), res.end());

        return res;
    }
};

// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1