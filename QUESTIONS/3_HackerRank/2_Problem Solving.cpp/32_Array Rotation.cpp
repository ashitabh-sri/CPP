// https://www.hackerrank.com/challenges/circular-array-rotation/problem?isFullScreen=true

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries)
{
    vector<int> a1 = a;
    for (int j = 0; j < a.size(); j++)
    {

        if (j + k <= a.size() - 1)
        {
            a1[j + k] = a[j];
        }

        if (j + k > a.size() - 1)
        {
            a1[(j + k) % (a.size())] = a[j];
        }
    }

    vector<int> nums;
    for (int index : queries)
    {
        int num = a1[index];
        nums.push_back(num);
    }

    return nums;
}