// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

int minimumDistances(vector<int> a)
{
    int n = a.size(), mind = INT_MAX;

    for (int i = 0; i < n - 1; i++)
    {
        int dis = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                dis = j - i;
                mind = min(mind, dis);
                break;
            }
        }
    }

    return mind == INT_MAX ? -1 : mind;
}