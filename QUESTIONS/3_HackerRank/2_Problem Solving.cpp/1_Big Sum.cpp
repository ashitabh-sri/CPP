// https://www.hackerrank.com/challenges/a-very-big-sum/problem?isFullScreen=true

long aVeryBigSum(vector<long> ar)
{

    long unsigned iz = 0;
    long unsigned total = 0;
    for (iz; iz < ar.size(); iz++)
    {
        total += ar[iz];
    }

    return total;
}