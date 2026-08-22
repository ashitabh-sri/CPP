// https://www.hackerrank.com/challenges/matrix-rotation-algo/problem?isFullScreen=true

void matrixRotation(vector<vector<int>> matrix, int r)
{
    int m = matrix.size(), n = matrix[0].size();

    for (int layer = 0; layer < min(m, n) / 2; layer++)
    {
        int top = layer, left = layer;
        int bottom = m - layer - 1;
        int right = n - layer - 1;

        vector<pair<int, int>> pos;

        // Top row
        for (int j = left; j <= right; j++)
            pos.push_back({top, j});

        // Right column
        for (int i = top + 1; i < bottom; i++)
            pos.push_back({i, right});

        // Bottom row
        for (int j = right; j >= left; j--)
            pos.push_back({bottom, j});

        // Left column
        for (int i = bottom - 1; i > top; i--)
            pos.push_back({i, left});

        vector<int> vals;
        for (auto [x, y] : pos)
            vals.push_back(matrix[x][y]);

        rotate(vals.begin(), vals.begin() + (r % vals.size()), vals.end());

        for (int i = 0; i < pos.size(); i++)
            matrix[pos[i].first][pos[i].second] = vals[i];
    }

    for (auto &row : matrix)
    {
        for (int j = 0; j < row.size(); j++)
        {
            if (j)
                cout << " ";
            cout << row[j];
        }
        cout << '\n';
    }
}