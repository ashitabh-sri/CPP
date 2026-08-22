// https://www.hackerrank.com/challenges/compare-the-triplets/problem?isFullScreen=true

vector<int> compareTriplets(vector<int> a, vector<int> b)
{
    vector<int> arr(2);
    int s = a.size();
    for (int i = 0; i < s; i++)
    {
        if (a[i] > b[i])
        {
            arr[0]++;
        }
        else if (a[i] < b[i])
        {
            arr[1]++;
        }
    }
    return arr;
}