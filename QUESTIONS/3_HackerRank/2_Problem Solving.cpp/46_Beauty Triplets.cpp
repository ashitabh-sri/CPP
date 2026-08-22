// https://www.hackerrank.com/challenges/beautiful-triplets/problem?isFullScreen=true

int beautifulTriplets(int d, vector<int> arr)
{
    int nob = 0;
    int n = arr.size();

    for (int a : arr)
    {
        bool chk1 = false, chk2 = false;
        if (find(arr.begin(), arr.end(), a + d) != arr.end())
            chk1 = true;
        if (find(arr.begin(), arr.end(), a + d + d) != arr.end())
            chk2 = true;
        if (chk1 && chk2)
            nob++;
    }

    return nob;
}