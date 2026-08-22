// https://www.hackerrank.com/challenges/the-quickest-way-up/problem

int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes)
{

    vector<int> board(101);

    // Initialize board
    for (int i = 1; i <= 100; i++)
    {
        board[i] = i;
    }

    // Add ladders
    for (auto &ladder : ladders)
    {
        board[ladder[0]] = ladder[1];
    }

    // Add snakes
    for (auto &snake : snakes)
    {
        board[snake[0]] = snake[1];
    }

    vector<bool> visited(101, false);

    queue<pair<int, int>> q;
    // {current position, number of moves}

    q.push({1, 0});
    visited[1] = true;

    while (!q.empty())
    {
        int pos = q.front().first;
        int moves = q.front().second;
        q.pop();

        // Reached destination
        if (pos == 100)
            return moves;

        // Try dice values
        for (int dice = 1; dice <= 6; dice++)
        {
            int next = pos + dice;

            if (next <= 100 && !visited[next])
            {

                // Move through ladder or snake
                int destination = board[next];

                visited[destination] = true;
                q.push({destination, moves + 1});
            }
        }
    }

    return -1;
}