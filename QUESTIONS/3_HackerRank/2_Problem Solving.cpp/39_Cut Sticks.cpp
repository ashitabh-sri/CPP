// https://www.hackerrank.com/challenges/cut-the-sticks/problem?isFullScreen=true

vector<int> cutTheSticks(vector<int> arr)
{
    vector<int> nst;
    int n = arr.size();
    nst.push_back(n);

    while (arr.size() > 0)
    {
        int mini = *min_element(arr.begin(), arr.end());
        for (int &a : arr)
            a -= mini;
        arr.erase(remove(arr.begin(), arr.end(), 0), arr.end());
        if (arr.size() >= 1)
            nst.push_back(arr.size());
    }

    return nst;
}