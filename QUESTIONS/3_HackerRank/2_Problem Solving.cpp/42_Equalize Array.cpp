// https://www.hackerrank.com/challenges/equality-in-a-array/problem?isFullScreen=true

int equalizeArray(vector<int> arr)
{
    vector<int> F(100, 0);

    for (int a : arr)
        F[a - 1]++;
    int maxf = *max_element(F.begin(), F.end()), ttlf = arr.size();

    return ttlf - maxf;
}