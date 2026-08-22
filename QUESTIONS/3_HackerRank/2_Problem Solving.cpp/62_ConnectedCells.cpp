// https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem

int connectedCell(vector<vector<int>> matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    function<int(int, int)> dfs = [&](int x, int y)
    {
        visited[x][y] = 1;

        int count = 1;

        for (int i = 0; i < 8; i++)
        {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                matrix[nx][ny] == 1 && !visited[nx][ny])
            {

                count += dfs(nx, ny);
            }
        }

        return count;
    };

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (matrix[i][j] == 1 && !visited[i][j])
            {

                ans = max(ans, dfs(i, j));
            }
        }
    }

    return ans;
}