// https://www.hackerrank.com/challenges/diagonal-difference/problem?isFullScreen=true

int diagonalDifference(vector<vector<int>> arr)
{

    int first = 0;
    int second = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        first += arr[i][i];
    }

    for (int j = n - 1, i = 0; j >= 0, i < n; j--, i++)
    {
        second += arr[i][j];
    }

    int answer = first - second;
    int outputt = abs(answer);

    return outputt;
}