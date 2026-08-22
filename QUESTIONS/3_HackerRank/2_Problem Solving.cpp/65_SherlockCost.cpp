// https://www.hackerrank.com/challenges/sherlock-and-cost/problem

int cost(vector<int> B)
{

    int n = B.size();

    // low -> maximum cost when A[i] = 1
    // high -> maximum cost when A[i] = B[i]

    int low = 0;
    int high = 0;

    for (int i = 1; i < n; i++)
    {

        int newLow = max(
            low,
            high + abs(B[i - 1] - 1));

        int newHigh = max(
            low + abs(B[i] - 1),
            high + abs(B[i] - B[i - 1]));

        low = newLow;
        high = newHigh;
    }

    return max(low, high);
}