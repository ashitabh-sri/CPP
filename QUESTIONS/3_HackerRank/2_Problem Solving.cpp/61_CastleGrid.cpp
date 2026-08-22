// https://www.hackerrank.com/challenges/castle-on-the-grid/problem

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
{

    int n = grid.size();

    vector<vector<int>> dist(n, vector<int>(n, -1));

    queue<pair<int, int>> q;

    q.push({startX, startY});
    dist[startX][startY] = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty())
    {

        auto [x, y] = q.front();
        q.pop();

        if (x == goalX && y == goalY)
            return dist[x][y];

        for (int dir = 0; dir < 4; dir++)
        {

            int nx = x + dx[dir];
            int ny = y + dy[dir];

            while (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] != 'X')
            {

                if (dist[nx][ny] == -1)
                {

                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }

                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }

    return -1;
}