// https://www.hackerrank.com/challenges/red-knights-shortest-path/problem?isFullScreen=true

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end)
{
    vector<vector<int>> dist(n, vector<int>(n, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, {-1, -1}));
    vector<vector<string>> moveUsed(n, vector<string>(n, ""));

    vector<pair<pair<int, int>, string>> moves = {
        {{-2, -1}, "UL"},
        {{-2, 1}, "UR"},
        {{0, 2}, "R"},
        {{2, 1}, "LR"},
        {{2, -1}, "LL"},
        {{0, -2}, "L"}};

    queue<pair<int, int>> q;
    q.push({i_start, j_start});
    dist[i_start][j_start] = 0;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto &m : moves)
        {
            int nx = x + m.first.first;
            int ny = y + m.first.second;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                moveUsed[nx][ny] = m.second;
                q.push({nx, ny});
            }
        }
    }

    if (dist[i_end][j_end] == -1)
    {
        cout << "Impossible\n";
        return;
    }

    vector<string> path;

    int x = i_end, y = j_end;

    while (x != i_start || y != j_start)
    {
        path.push_back(moveUsed[x][y]);
        auto p = parent[x][y];
        x = p.first;
        y = p.second;
    }

    reverse(path.begin(), path.end());

    cout << dist[i_end][j_end] << "\n";

    for (string s : path)
    {
        cout << s << " ";
    }
    cout << "\n";
}