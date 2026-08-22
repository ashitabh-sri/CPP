// https://www.hackerrank.com/challenges/mini-max-sum/problem?isFullScreen=true

void miniMaxSum(vector<int> arr)
{

    long unsigned maxi = arr[0];
    for (long unsigned i = 1; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    long unsigned maxsuum = 0;
    for (long unsigned j = 0; j < arr.size(); j++)
    {
        maxsuum += arr[j];
    }
    maxsuum -= maxi;

    long unsigned mini = arr[0];
    for (long unsigned k = 1; k < arr.size(); k++)
    {
        if (arr[k] < mini)
        {
            mini = arr[k];
        }
    }
    long unsigned minsuum = 0;
    for (long unsigned l = 0; l < arr.size(); l++)
    {
        minsuum += arr[l];
    }
    minsuum -= mini;

    cout << maxsuum << " " << minsuum;
}